#pragma once
#ifndef BOMB_H
#define BOMB_H
#include <QObject>
#include <ctime>

class bomb :public QObject{
    Q_OBJECT
private:
    int dir;
public:
    bomb();
    bomb(int direction);
    virtual ~bomb(){}
    int direction();
    void setdir(){dir=rand()%4;}//방향을 리턴해주는 함수

public slots:
    void changedir(); //시계방향으로 돌리는 함수

};


#endif BOMB_H
