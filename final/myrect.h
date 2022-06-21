#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class MyRect : public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect(int ,int );
    void change_position(int x, int y);
    void keyPressEvent(QKeyEvent *event);
    int get_x(){return pos_x;}
    int get_y(){return pos_y;}
private:
    int pos_x,pos_y;

signals:
    void change_dir();
    void up_bomb();
};

#endif // MYRECT_H
