/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Normalmode_button;
    QPushButton *Exit_button;
    QPushButton *Timeattack_button;
    QPushButton *Ranking_button;
    QGraphicsView *view_Main;
    QGraphicsView *view_Normalmode;
    QGraphicsView *view_TimeAttack;
    QGraphicsView *view_Ranking;
    QTabWidget *Ranking_tabwidget;
    QWidget *Normal;
    QLabel *Name_2;
    QLabel *Score_2;
    QLabel *name1;
    QLabel *score1;
    QLabel *name2;
    QLabel *score2;
    QLabel *name3;
    QLabel *score3;
    QWidget *TimeAttack;
    QLabel *Name;
    QLabel *Score;
    QLabel *score3_2;
    QLabel *score1_2;
    QLabel *name1_2;
    QLabel *name3_2;
    QLabel *name2_2;
    QLabel *score2_2;
    QPushButton *Backtomenu_button;
    QGraphicsView *Bomblink_picture;
    QGraphicsView *view_Game_over;
    QPushButton *PlayAgain_button;
    QLineEdit *name;
    QLabel *score;
    QPushButton *save;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 550);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Normalmode_button = new QPushButton(centralWidget);
        Normalmode_button->setObjectName(QString::fromUtf8("Normalmode_button"));
        Normalmode_button->setGeometry(QRect(140, 260, 160, 30));
        Exit_button = new QPushButton(centralWidget);
        Exit_button->setObjectName(QString::fromUtf8("Exit_button"));
        Exit_button->setGeometry(QRect(140, 440, 160, 30));
        Timeattack_button = new QPushButton(centralWidget);
        Timeattack_button->setObjectName(QString::fromUtf8("Timeattack_button"));
        Timeattack_button->setGeometry(QRect(140, 320, 160, 30));
        Ranking_button = new QPushButton(centralWidget);
        Ranking_button->setObjectName(QString::fromUtf8("Ranking_button"));
        Ranking_button->setGeometry(QRect(140, 380, 160, 30));
        view_Main = new QGraphicsView(centralWidget);
        view_Main->setObjectName(QString::fromUtf8("view_Main"));
        view_Main->setGeometry(QRect(0, 0, 450, 520));
        view_Main->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/sky.png);"));
        QBrush brush(QColor(85, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        view_Main->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        view_Main->setForegroundBrush(brush1);
        view_Normalmode = new QGraphicsView(centralWidget);
        view_Normalmode->setObjectName(QString::fromUtf8("view_Normalmode"));
        view_Normalmode->setGeometry(QRect(0, 0, 450, 520));
        view_Normalmode->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/sky.png);"));
        view_TimeAttack = new QGraphicsView(centralWidget);
        view_TimeAttack->setObjectName(QString::fromUtf8("view_TimeAttack"));
        view_TimeAttack->setGeometry(QRect(0, 0, 450, 520));
        view_TimeAttack->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/sky.png);"));
        view_Ranking = new QGraphicsView(centralWidget);
        view_Ranking->setObjectName(QString::fromUtf8("view_Ranking"));
        view_Ranking->setGeometry(QRect(0, 0, 450, 520));
        view_Ranking->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/sky.png);"));
        Ranking_tabwidget = new QTabWidget(centralWidget);
        Ranking_tabwidget->setObjectName(QString::fromUtf8("Ranking_tabwidget"));
        Ranking_tabwidget->setGeometry(QRect(90, 90, 261, 311));
        Ranking_tabwidget->setStyleSheet(QString::fromUtf8(""));
        Ranking_tabwidget->setTabPosition(QTabWidget::South);
        Ranking_tabwidget->setIconSize(QSize(16, 16));
        Ranking_tabwidget->setUsesScrollButtons(false);
        Normal = new QWidget();
        Normal->setObjectName(QString::fromUtf8("Normal"));
        Name_2 = new QLabel(Normal);
        Name_2->setObjectName(QString::fromUtf8("Name_2"));
        Name_2->setGeometry(QRect(50, 10, 61, 41));
        Score_2 = new QLabel(Normal);
        Score_2->setObjectName(QString::fromUtf8("Score_2"));
        Score_2->setGeometry(QRect(165, 10, 61, 41));
        name1 = new QLabel(Normal);
        name1->setObjectName(QString::fromUtf8("name1"));
        name1->setGeometry(QRect(40, 80, 64, 15));
        score1 = new QLabel(Normal);
        score1->setObjectName(QString::fromUtf8("score1"));
        score1->setGeometry(QRect(160, 80, 64, 15));
        name2 = new QLabel(Normal);
        name2->setObjectName(QString::fromUtf8("name2"));
        name2->setGeometry(QRect(40, 120, 64, 15));
        score2 = new QLabel(Normal);
        score2->setObjectName(QString::fromUtf8("score2"));
        score2->setGeometry(QRect(160, 120, 64, 15));
        name3 = new QLabel(Normal);
        name3->setObjectName(QString::fromUtf8("name3"));
        name3->setGeometry(QRect(40, 160, 64, 15));
        score3 = new QLabel(Normal);
        score3->setObjectName(QString::fromUtf8("score3"));
        score3->setGeometry(QRect(160, 160, 64, 15));
        Ranking_tabwidget->addTab(Normal, QString());
        TimeAttack = new QWidget();
        TimeAttack->setObjectName(QString::fromUtf8("TimeAttack"));
        Name = new QLabel(TimeAttack);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(50, 10, 61, 41));
        Name->setStyleSheet(QString::fromUtf8(""));
        Score = new QLabel(TimeAttack);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(165, 10, 61, 41));
        score3_2 = new QLabel(TimeAttack);
        score3_2->setObjectName(QString::fromUtf8("score3_2"));
        score3_2->setGeometry(QRect(160, 160, 64, 15));
        score1_2 = new QLabel(TimeAttack);
        score1_2->setObjectName(QString::fromUtf8("score1_2"));
        score1_2->setGeometry(QRect(160, 80, 64, 15));
        name1_2 = new QLabel(TimeAttack);
        name1_2->setObjectName(QString::fromUtf8("name1_2"));
        name1_2->setGeometry(QRect(40, 80, 64, 15));
        name3_2 = new QLabel(TimeAttack);
        name3_2->setObjectName(QString::fromUtf8("name3_2"));
        name3_2->setGeometry(QRect(40, 160, 64, 15));
        name2_2 = new QLabel(TimeAttack);
        name2_2->setObjectName(QString::fromUtf8("name2_2"));
        name2_2->setGeometry(QRect(40, 120, 64, 15));
        score2_2 = new QLabel(TimeAttack);
        score2_2->setObjectName(QString::fromUtf8("score2_2"));
        score2_2->setGeometry(QRect(160, 120, 64, 15));
        Ranking_tabwidget->addTab(TimeAttack, QString());
        Backtomenu_button = new QPushButton(centralWidget);
        Backtomenu_button->setObjectName(QString::fromUtf8("Backtomenu_button"));
        Backtomenu_button->setGeometry(QRect(270, 440, 160, 30));
        Bomblink_picture = new QGraphicsView(centralWidget);
        Bomblink_picture->setObjectName(QString::fromUtf8("Bomblink_picture"));
        Bomblink_picture->setGeometry(QRect(85, 40, 281, 181));
        Bomblink_picture->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/bomblink.PNG);"));
        view_Game_over = new QGraphicsView(centralWidget);
        view_Game_over->setObjectName(QString::fromUtf8("view_Game_over"));
        view_Game_over->setGeometry(QRect(0, 0, 450, 520));
        view_Game_over->setStyleSheet(QString::fromUtf8("border-image: url(:/Picture/Picture/sky.png);"));
        PlayAgain_button = new QPushButton(centralWidget);
        PlayAgain_button->setObjectName(QString::fromUtf8("PlayAgain_button"));
        PlayAgain_button->setGeometry(QRect(120, 360, 211, 71));
        name = new QLineEdit(centralWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(160, 230, 113, 21));
        score = new QLabel(centralWidget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(145, 170, 161, 61));
        save = new QPushButton(centralWidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(275, 226, 51, 28));
        MainWindow->setCentralWidget(centralWidget);
        Ranking_tabwidget->raise();
        name->raise();
        save->raise();
        score->raise();
        PlayAgain_button->raise();
        view_Game_over->raise();
        Backtomenu_button->raise();
        view_Normalmode->raise();
        view_TimeAttack->raise();
        view_Ranking->raise();
        view_Main->raise();
        Ranking_button->raise();
        Exit_button->raise();
        Timeattack_button->raise();
        Normalmode_button->raise();
        Bomblink_picture->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 450, 29));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Ranking_tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Normalmode_button->setText(QApplication::translate("MainWindow", "1. Normal mode", nullptr));
        Exit_button->setText(QApplication::translate("MainWindow", "4. Exit", nullptr));
        Timeattack_button->setText(QApplication::translate("MainWindow", "2. Time attack", nullptr));
        Ranking_button->setText(QApplication::translate("MainWindow", "3. Ranking", nullptr));
        Name_2->setText(QApplication::translate("MainWindow", "Name", nullptr));
        Score_2->setText(QApplication::translate("MainWindow", "Score", nullptr));
        name1->setText(QString());
        score1->setText(QString());
        name2->setText(QString());
        score2->setText(QString());
        name3->setText(QString());
        score3->setText(QString());
        Ranking_tabwidget->setTabText(Ranking_tabwidget->indexOf(Normal), QApplication::translate("MainWindow", "Normal", nullptr));
        Name->setText(QApplication::translate("MainWindow", "Name", nullptr));
        Score->setText(QApplication::translate("MainWindow", "Score", nullptr));
        score3_2->setText(QString());
        score1_2->setText(QString());
        name1_2->setText(QString());
        name3_2->setText(QString());
        name2_2->setText(QString());
        score2_2->setText(QString());
        Ranking_tabwidget->setTabText(Ranking_tabwidget->indexOf(TimeAttack), QApplication::translate("MainWindow", "TimeAttack", nullptr));
        Backtomenu_button->setText(QApplication::translate("MainWindow", "<- Back to Menu", nullptr));
        PlayAgain_button->setText(QApplication::translate("MainWindow", "Game Over! Try Again?", nullptr));
        score->setText(QApplication::translate("MainWindow", "    Enter your name!", nullptr));
        save->setText(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
