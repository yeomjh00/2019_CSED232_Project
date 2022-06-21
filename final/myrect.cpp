#include "myrect.h"
#include <QDebug>

MyRect::MyRect(int x, int y):pos_x(x),pos_y(y)
{
    //setPos(pos_x,pos_y);
}

void MyRect::change_position(int x, int y)  //행렬의 index를 받아서 실제 좌표로 변환하여 rect(커서)를 이동시킴
{
    setPos(40*x,-400+50*(9-y)); //실제 좌표와 비교해서 다시 대입해줘야함
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Right){
        if(pos_x<4)
            pos_x++;
    }
    else if(event->key()==Qt::Key_Left){
        if(pos_x>0)
            pos_x--;
    }
    else if(event->key()==Qt::Key_Down){
        if(pos_y>1)
            pos_y--;
    }
    else if(event->key()==Qt::Key_Up){
      if(pos_y<8)    //현재 커서의 위에 폭탄이 존재하면
            pos_y++;
    }
    else if(event->key()==Qt::Key_B){
        emit up_bomb();
    }
    else if(event->key()==Qt::Key_Space){
        emit change_dir();
    }

    change_position(pos_x,pos_y); //바뀐 위치로 사용자 커서(rect) 그려주기
}
