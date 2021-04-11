#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"
#include "Enemy.h"
#include "Boom.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    if((game->gameMode!="twoPlayersMode"))
    {
        int random_number = rand() % 1520+200;
        setPos(random_number,0);
    }
    else if((game->gameMode=="twoPlayersMode"))
    {
        if(!game->health->gameOverState())
        {
            int random_number = rand() % 760+1060;

            setPos(random_number,0);
        }
        else if(!game->healthTwo->gameOverState())
        {
            int random_number = rand() % 760+100;
            setPos(random_number,0);
        }
        else
        {
            int random_number = rand() % 1720+100;
            setPos(random_number,0);
        }

    }

    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(13);

    boomSound = new QMediaPlayer();
    boomSound->setMedia(QUrl("qrc:/sound/boom.mp3"));
    boomSound->setVolume(game->explosionVolume);
}


void Enemy::move()
{

    if((game->gameMode!="twoPlayersMode"))
    {
        if(game->health->gameOverState() && game->isGamePaused==false)
            setPos(x(),y()+game->enemySpeed);
    }
    else if((game->gameMode=="twoPlayersMode"))
    {
        if(game->isGamePaused==false)
        {
            if(pos().x() <960)
            {
                if(game->health->gameOverState())
                    setPos(x(),y()+3);
            }
            else if(pos().x() >960)
            {
                if(game->healthTwo->gameOverState())
                    setPos(x(),y()+3);
            }
        }
    }

    if(pos().y() > 910)
    {
        if(game->gameMode=="twoPlayersMode")
        {
            if(pos().x() <960)
                game->health->decrease();
            else
                game->healthTwo->decrease();
        }
        else
            game->health->decrease();

        game->lvl->enemyDestroyed();

        if(game->lvl->enemysToDestroy<=0 && game->health->gameOverState())
            game->lvl->lvlUp();

        Boom * boomImage = new Boom();
        boomImage->setPos(this->x(), this->y()+15);
        scene()->addItem(boomImage);

        if(boomSound->state() == QMediaPlayer::PlayingState)
            boomSound->setPosition(0);
        else if (boomSound->state() == QMediaPlayer::StoppedState)
            boomSound->play();

        scene()->removeItem(this);
        delete this;
        qDebug() << "przeciwnik usuniety";

    }
}
