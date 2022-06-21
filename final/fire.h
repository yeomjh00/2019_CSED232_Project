#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QImage>
#include <QGraphicsPixmapItem>

class fire : public QObject,public QGraphicsRectItem
{
private:
    Q_OBJECT
    QTimer* timer; //불의 움직임을 구현하기 위한 timer
    int pos[2]; //pos[0]은 좌우, 왼쪽은 0, 오른쪽 1, pos[1]은 y좌표 범위는 0<=y<9
    int count=0;
public:
    explicit fire(QObject *parent = nullptr);
    int r_left_or_right();
    int r_position();
    int get_count(){return count;}
signals:
    int changepos(int x, int y); //(좌우, y위치) 위치가 바뀌면서 신호 방출
    void t_gameover();

public slots:
    void down(); //타이머에서 down 호출 시, y좌표가 1만큼 감소하며 emit changepos
    void fire_stop();
    void fire_start();
};

#endif // FIRE_H
