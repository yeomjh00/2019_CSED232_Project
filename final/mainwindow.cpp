#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), user_name("Unknown"), pos_x(3), pos_y(3)
{
    ui->setupUi(this);
    QObject::connect(ui->Normalmode_button, SIGNAL(clicked()), this, SLOT(on_Normalmode_button_clicked()));
    QObject::connect(ui->Timeattack_button, SIGNAL(clicked()), this, SLOT(on_Timeattack_button_clicked()));
    QObject::connect(ui->Ranking_button, SIGNAL(clicked()), this, SLOT(on_Ranking_button_clicked()));
    QObject::connect(ui->Exit_button, SIGNAL(clicked()), this, SLOT(on_Exit_button_clicked()));
    QObject::connect(ui->save, SIGNAL(clicked()), this, SLOT(save_name()));
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Normalmode_button_clicked()
{
    normal = new Mode();
    QObject::connect(normal, SIGNAL(gameover(int)), this, SLOT(game_Over(int )));

    ui->view_Normalmode->setScene(normal);
    ui->view_Normalmode->setFocus();
    ui->view_Normalmode->show();
    ui->view_Normalmode->activateWindow();
    ui->view_Normalmode->raise();
}

void MainWindow::on_Timeattack_button_clicked()
{
    attack = new TimeAttack_mode();
    ui->view_TimeAttack->setScene(attack);
    ui->view_Normalmode->setFocus();
    ui->view_TimeAttack->show();
    ui->view_TimeAttack->activateWindow();
    ui->view_TimeAttack->raise();
}

void MainWindow::on_Ranking_button_clicked()
{
    ui->view_Ranking->show();
    ui->view_Ranking->activateWindow();
    ui->view_Ranking->raise();
    ui->Ranking_tabwidget->show();
    ui->Ranking_tabwidget->activateWindow();
    ui->Ranking_tabwidget->raise();
    ui->Backtomenu_button->show();
    ui->Backtomenu_button->activateWindow();
    ui->Backtomenu_button->raise();
    if (normal_ranking.size() == 1)
    {
        ui->name1->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-1].second));
        ui->score1->setNum(normal_ranking[normal_ranking.size()-1].first);
    }
    else if (normal_ranking.size() == 2)
    {
        ui->name1->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-1].second));
        ui->name2->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-2].second));
        ui->score1->setNum(normal_ranking[normal_ranking.size()-1].first);
        ui->score2->setNum(normal_ranking[normal_ranking.size()-2].first);
    }
    else if (normal_ranking.size() >= 3)
    {
        ui->name1->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-1].second));
        ui->name2->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-2].second));
        ui->name3->setText(QString::fromStdString(normal_ranking[normal_ranking.size()-3].second));
        ui->score1->setNum(normal_ranking[normal_ranking.size()-1].first);
        ui->score2->setNum(normal_ranking[normal_ranking.size()-2].first);
        ui->score3->setNum(normal_ranking[normal_ranking.size()-3].first);
    }
    if (tattack_ranking.size() == 1)
    {
        ui->name1_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-1].second));
        ui->score1_2->setNum(tattack_ranking[tattack_ranking.size()-1].first);
    }
    else if (tattack_ranking.size() == 2)
    {
        ui->name1_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-1].second));
        ui->name2_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-2].second));
        ui->score1_2->setNum(tattack_ranking[tattack_ranking.size()-1].first);
        ui->score2_2->setNum(tattack_ranking[tattack_ranking.size()-2].first);
    }
    else if (normal_ranking.size() >= 3)
    {
        ui->name1_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-1].second));
        ui->name2_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-2].second));
        ui->name3_2->setText(QString::fromStdString(tattack_ranking[tattack_ranking.size()-3].second));
        ui->score1_2->setNum(tattack_ranking[tattack_ranking.size()-1].first);
        ui->score2_2->setNum(tattack_ranking[tattack_ranking.size()-2].first);
        ui->score3_2->setNum(tattack_ranking[tattack_ranking.size()-3].first);
    }
}

void MainWindow::on_Exit_button_clicked()
{
    QApplication::quit();
}

void MainWindow::on_Backtomenu_button_clicked()
{
    ui->view_Main->show();
    ui->view_Main->activateWindow();
    ui->view_Main->raise();
    ui->Normalmode_button->show();
    ui->Normalmode_button->activateWindow();
    ui->Normalmode_button->raise();
    ui->Timeattack_button->show();
    ui->Timeattack_button->activateWindow();
    ui->Timeattack_button->raise();
    ui->Ranking_button->show();
    ui->Ranking_button->activateWindow();
    ui->Ranking_button->raise();
    ui->Exit_button->show();
    ui->Exit_button->activateWindow();
    ui->Exit_button->raise();
    ui->Bomblink_picture->show();
    ui->Bomblink_picture->activateWindow();
    ui->Bomblink_picture->raise();
}
void MainWindow::game_Over(int point)
{
    delete normal;
    score = point;
    ui->view_Game_over->show();
    ui->view_Game_over->activateWindow();
    ui->view_Game_over->raise();
    ui->PlayAgain_button->show();
    ui->PlayAgain_button->activateWindow();
    ui->PlayAgain_button->raise();
    ui->name->show();
    ui->name->activateWindow();
    ui->name->raise();
    ui->score->show();
    ui->score->activateWindow();
    ui->score->raise();
    ui->save->show();
    ui->save->activateWindow();
    ui->save->raise();
}


void MainWindow::on_PlayAgain_button_clicked()
{
    ui->view_Main->show();
    ui->view_Main->activateWindow();
    ui->view_Main->raise();
    ui->Normalmode_button->show();
    ui->Normalmode_button->activateWindow();
    ui->Normalmode_button->raise();
    ui->Timeattack_button->show();
    ui->Timeattack_button->activateWindow();
    ui->Timeattack_button->raise();
    ui->Ranking_button->show();
    ui->Ranking_button->activateWindow();
    ui->Ranking_button->raise();
    ui->Exit_button->show();
    ui->Exit_button->activateWindow();
    ui->Exit_button->raise();
    ui->Bomblink_picture->show();
    ui->Bomblink_picture->activateWindow();
    ui->Bomblink_picture->raise();
}

void MainWindow::save_name(){
    //타임어택 모드를 구현하려고 했으나, 타임어택 모드 구현을 완벽히 하지 않아 이미 구현해둔 save 기능을 주석처리 하였다.
    user_name=ui->name->text().toStdString();
    //if(typeid(*normal)==typeid(Mode))
        normal_ranking.push_back(std::pair<int, std::string>(score, user_name));
    //else if(typeid(*normal)==typeid(TimeAttack_mode))
        //tattack_ranking.push_back(std::pair<int,std::string>(score,user_name));
    std::sort(normal_ranking.begin(),normal_ranking.end());
    std::sort(tattack_ranking.begin(),tattack_ranking.end());
}
