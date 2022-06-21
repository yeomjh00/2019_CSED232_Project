#include "game_mode.h"
#include "gameboard.h"
#include <QDebug>

Mode::Mode():count(0), n(0), score(0)
{
    //커서 초기값 지정
    init_x =0;
    init_y =1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
            arr[i][j] = 0;
    }

    //게임 판 출력
    QGraphicsRectItem *fire_leftrect = new QGraphicsRectItem();
        fire_leftrect->setRect(-152, -97, 50, 395);
        this->addItem(fire_leftrect);
        fire_leftrect->setFocus();
        QGraphicsRectItem *fire_rightrect = new QGraphicsRectItem();
        fire_rightrect->setRect(107, -97, 50, 395);
        this->addItem(fire_rightrect);
        fire_rightrect->setFocus();

        QGraphicsRectItem *endbar = new QGraphicsRectItem();
        endbar->setRect(-152, -104, 309, 5);
        this->addItem(endbar);

        QGraphicsRectItem *bombbar = new QGraphicsRectItem();
        bombbar->setRect(-223, 300, 446, 10);
        bombbar->setBrush(Qt::black);
        this->addItem(bombbar);

        QGraphicsRectItem *asdf = new QGraphicsRectItem();
            asdf->setRect(-223, -150, 0.1, 0.1);
            asdf->setBrush(Qt::black);
            this->addItem(asdf);

    //점수 저장을 위한 class
            cur_score = new Score();
            cur_score->setPos(-223, -150);
            addItem(cur_score);

    //커서를 위해 필요한 rect 생성
    rect=new MyRect(init_x,init_y);
    rect->setRect(-100,253,45,45);
    this->addItem(rect);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //게임보드, 폭탄 생성
    Board = new gameboard();
    //폭탄 출력
    Fire = new fire();
    printprint();

    firetimer= new QTimer();
    firetimer->start(10000);
    //10초마다 폭탄생성
    QObject::connect(firetimer,SIGNAL(timeout()),Board,SLOT(generatebomb()));


    //폭탄과 만났을 때 시간 멈추고, 폭발 끝나면 다시 시작
    QObject::connect(Board,SIGNAL(stop()),firetimer,SLOT(stop()));
    QObject::connect(Board,SIGNAL(start()),this,SLOT(restartfire()));


    //방향 바꾸기
    QObject::connect(rect,SIGNAL(change_dir()),this,SLOT(change_bomb_dir()));
    QObject::connect(this,SIGNAL(bomb_reprint()),this,SLOT(printprint()));

    //사용자가 폭탄 직접 올려주기
    QObject::connect(rect,SIGNAL(up_bomb()),Board,SLOT(generatebomb()));

    // 불 0.5초마다 출력
    QObject::connect(Fire, SIGNAL(changepos(int, int)), this, SLOT(printprint()));

    //
    QObject::connect(Board, SIGNAL(start()), Fire, SLOT(fire_start()));
    QObject::connect(Board, SIGNAL(stop()), Fire, SLOT(fire_stop()));
    QObject::connect(Fire, SIGNAL(changepos(int, int)), Board, SLOT(is_explode(int, int)));

    QObject::connect(Board,SIGNAL(board_change()),this,SLOT(printprint()));

    curser_timer = new QTimer();
    curser_timer->start(100);

    //점수 체크
    QObject::connect(Board, SIGNAL(score(int)), this, SLOT(plus_score(int)));
    QObject::connect(curser_timer, SIGNAL(timeout()), this, SLOT(printprint()));

    //게임오버
    QObject::connect(Board,SIGNAL(gameover()),this,SLOT(oversignal()));


}
void Mode::printBomb(bomb*arr[][5], fire *fire)
{
    init_x=rect->get_x();
    init_y=rect->get_y();

    if(n== 0){
        for (int i = 0; i < 51; i++)
        {
            image[i]=nullptr;
        }
    }
    if (n >= 1)
    {
        for (int i = 0; i < 51; i++)
        {
            if(image[i]!=nullptr)
            removeItem(image[i]);
        }
    }
    n++;

    //불이미지 생성
    QImage fire_image(":/Picture/Picture/fire.png");
    fire_image = fire_image.scaled(50, 50, Qt::KeepAspectRatio);
    if (fire->r_position() == 0) {}
    else if (fire->r_left_or_right() == 0)
    {
        image[50] = new QGraphicsPixmapItem(QPixmap::fromImage(fire_image));
        addItem(image[50]);
        image[50]->setPos(-150, -150 + 50 * (9 - fire->r_position()));
    }
    else
    {
        image[50] = new QGraphicsPixmapItem(QPixmap::fromImage(fire_image));
        addItem(image[50]);
        image[50]->setPos(106, -150 + 50 * (9 - fire->r_position()));
    }

    QImage left_bomb(":/Picture/Picture/bomb_left.png");
    QImage right_bomb(":/Picture/Picture/bomb_right.png");
    QImage up_bomb(":/Picture/Picture/bomb_up.png");
    QImage down_bomb(":/Picture/Picture/bomb_down.png");
    up_bomb = up_bomb.scaled(50, 50, Qt::KeepAspectRatio);
    left_bomb = left_bomb.scaled(50, 50, Qt::KeepAspectRatio);
    right_bomb = right_bomb.scaled(50, 50, Qt::KeepAspectRatio);
    down_bomb = down_bomb.scaled(50, 50, Qt::KeepAspectRatio);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if(arr[i][j]==nullptr){
                continue;
            }
            else if (i == 0){

                if(arr[i][j]==nullptr){
                    ;
                }
                else if (arr[i][j]->direction() == 0)
                {
                    image[i*5+j]= new QGraphicsPixmapItem(QPixmap::fromImage(up_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -137 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 1)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(right_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -137 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 2)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(down_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -137 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 3)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(left_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -137 + 50 * (9 -i));
                }
            }

            else {

                if (arr[i][j]->direction() == 0)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(up_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -150 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 1)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(right_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -150 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 2)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(down_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -150 + 50 * (9 -i));
                }
                else if (arr[i][j]->direction() == 3)
                {
                    image[i*5+j] = new QGraphicsPixmapItem(QPixmap::fromImage(left_bomb));
                    addItem(image[i*5+j]);
                    image[i*5+j]->setPos(-100 + 40 * j, -150 + 50 * (9 -i));
                }
            }
        }
    }
}

void Mode::keyPressEvent(QKeyEvent *event){
    rect->keyPressEvent(event);
}


void Mode::restartfire(){
    firetimer->start(10000);
}

void Mode::change_bomb_dir(){
    if(bomb_arr[rect->get_y()][rect->get_x()]!=nullptr)
    {
        Board->change_direction(rect->get_y(),rect->get_x());
        emit bomb_reprint();
    }
}

void Mode::printprint(){


    for(int i=0; i<10; i++)
    {
        for(int j=0;j<5;j++)
        {
            bomb_arr[i][j] = Board->get_bomb(i,j);
        }
    }
    printBomb(bomb_arr, Fire);
}

void Mode::oversignal(){
    emit gameover(score);
    firetimer->stop();
    Fire->fire_stop();
}

void Mode::plus_score(int a){
    score+=a;
    cur_score->print_score(score);
}

TimeAttack_mode::TimeAttack_mode():Mode(){
QObject::connect(Fire, SIGNAL(t_gameover()), this, SLOT(oversignal()));
    //점수 저장을 위한 class
            num_fire = new Score();
            num_fire->setPos(-223, 0);
            addItem(num_fire);
}
void TimeAttack_mode::keyPressEvent(QKeyEvent *event){
    rect->keyPressEvent(event);
}
