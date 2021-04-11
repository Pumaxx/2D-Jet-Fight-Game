#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QtSql>
#include "Score.h"

class Health: public QGraphicsTextItem
{
    Q_OBJECT

    public:
        Health(QGraphicsItem * parent=0);
        void decrease();
        void drawGameOver(int xStart, int yStart, int width, int height,QColor color, double opacity);
        void putScoreToDatabase();
        int getHealth();
        bool gameOverState();
        bool gameOverStateTwo();
        bool isPlayerOneHealth;
        Score * endGameScore;
        Score * highScoreOne;
        Score * highScoreTwo;
        Score * highScoreThree;
        Health * gameOverText;
        QSqlDatabase dataBase;
        QString highScoresTable[3];
        QGraphicsTextItem* gameOverTextOne;
        QGraphicsTextItem*  endGameScoreOne;

    public slots:
        void restartGamee();
        void menuButton();

    private:
        int health;
        QMediaPlayer * gameOverSound;
};

#endif // HEALTH_H
