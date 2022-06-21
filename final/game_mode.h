#ifndef GAME_MODE_H
#define GAME_MODE_H
#include<QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include "myrect.h"
#include "gameboard.h"
#include<QDebug>
#include "score.h"
class Mode: public QGraphicsScene{
    Q_OBJECT
public:
    Mode();
    void printBomb(bomb* arr[][5], fire* fire);
    virtual void keyPressEvent(QKeyEvent * event);
    gameboard* r_board() {return Board;}
    gameboard* Board;
private:
    int init_x,init_y;
    int arr[10][5];
    QTimer* firetimer;
    int count;
    int n;
    int score;
    bomb* bomb_arr [10][5];
    QTimer* curser_timer;
    QGraphicsPixmapItem* image[51];
    QGraphicsRectItem* Rect[5];
    Score * cur_score;

protected:
    fire* Fire;
     MyRect *rect;//커서 표시(사각형)

public slots:
    void restartfire();
    void change_bomb_dir();
    void printprint();
    void oversignal();
    void plus_score(int a);
signals:
     void bomb_reprint();
     void print_again();
     void gameover(int point);
};

class Normal_Mode: public Mode{
public:
};

class TimeAttack_mode: public Mode{
public:
    TimeAttack_mode();
    virtual void keyPressEvent(QKeyEvent * event);
private:
    Score * num_fire=0;
};

#endif // GAME_MODE_H
