#include "fire.h"


fire::fire(QObject *parent) : QObject(parent){
    timer = new QTimer();
    srand(time(NULL));
    pos[0]=rand()%2; //왼쪽은 0, 오른쪽은 1
    pos[1]=9; //y위치가 10까지이고, 게임오버라인이 10번째 줄이므로, 배열에서는 9번째이다. 이 줄에서는 폭탄이 터지면 안되므로 y_max=8
              //그런데 down signal을 보면 y좌표를 줄이고 신호를 주기 때문에 9에서 시작한다.
    timer->start(500); //0.5초마다 신호를 준다.

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(down()));

}
int fire::r_left_or_right()
{
    return pos[0];
}
int fire::r_position()
{
   return pos[1];
}

void fire::down(){
    pos[1]--;
    if(pos[1]>-1)
        emit changepos(pos[0],pos[1]);
    else if(pos[1]<0)
    {
        srand(time(NULL));
        pos[0]=rand()%2; //왼쪽은 0, 오른쪽은 1
        pos[1]=9; //y위치가 10까지이고, 게임오버라인이 10번째 줄이므로, 배열에서는 9번째이다. 이 줄에서는 폭탄이 터지면 안되므로 y_max=8
                  //그런데 down signal을 보면 y좌표를 줄이고 신호를 주기 때문에 9에서 시작한다.
        count++;
        if(count>=100){
            emit t_gameover();
        }
    }
}

void fire::fire_stop(){
    timer->stop();
}
void fire::fire_start(){
    timer->start(500);
}
