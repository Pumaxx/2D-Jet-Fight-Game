#include <QFont>
#include <QTimer>
#include "Score.h"
#include "Game.h"

extern Game * game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::lightGray);
    setFont(QFont("times",25, QFont::Bold));
}

void Score::increase()
{
    score = score + 10 +(0.075*score);
    setPlainText(QString("Score: ") + QString::number(score));
}
int Score::getScore()
{
    return score;
}

void Score::setScore(int points)
{
    score= points;
    setPlainText(QString("Score: ") + QString::number(score));
}

