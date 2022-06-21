#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include "fire.h"
#include "bomb.h"
#include <queue>
#include <utility>
#include <ctime>

class game_mode;

class gameboard : public QObject
{
private:
    Q_OBJECT
    QTimer* timer;
    bool visited[10][5];
    bomb* board[10][5];
    int firecount;

public:
    explicit gameboard(QObject *parent = nullptr);
    void fallbomb();
    void change_direction(const int x,const int y);
    bomb* get_bomb(const int x, const int y);
    friend void printBomb();
    bomb* (*get_all_bomb())[5];
    int get_bomb_dir(const int x, const int y);

signals:
    void stop();
    void start();
    void board_change();
    void gameover();
    void score(int sc);

public slots:
    void catchfire(int x, int y);
    void generatebomb();
    void is_explode(int x, int y);
};

#endif // GAMEBOARD_H
