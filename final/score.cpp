#include "score.h"


#include <QFont>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent),score(0){
    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}


void Score::print_score(int sc){
    score=sc;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}
