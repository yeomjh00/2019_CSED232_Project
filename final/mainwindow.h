#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <string>
#include <vector>
#include <functional>
#include <QGraphicsRectItem>
#include "game_mode.h"
#include "gameboard.h"

namespace Ui {
class MainWindow;
}

class Ranking : public QMainWindow
{
public:
    void insert(std::string name, int score);
    std::multimap<std::string, int> rRank_info();

private:
    std::multimap<std::string, int> rank_info;
    std::vector<int> normal_ranking;
    std::vector<int> t_ranking;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_Timeattack_button_clicked();
    void on_Ranking_button_clicked();
    void on_Exit_button_clicked();
    void on_Normalmode_button_clicked();
    void on_Backtomenu_button_clicked();
    void game_Over(int point=0);
    void save_name();

private slots:
    void on_PlayAgain_button_clicked();
    void on_Ranking_tabwidget_tabBarClicked(int index);

private:
    std::string user_name;
    int score;
    std::vector<std::pair<int, std::string>> normal_ranking;
    std::vector<std::pair<int, std::string>> tattack_ranking;
    Mode* normal;
    Mode* attack;
    Ranking *ranking;
    Ui::MainWindow *ui;
    int pos_x , pos_y;   //사용자 커서 위치
};

#endif // MAINWINDOW_H
