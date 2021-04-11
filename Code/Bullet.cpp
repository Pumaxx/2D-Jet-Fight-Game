#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "Enemy.h"
#include "Game.h"
#include "Bullet.h"
#include "Boom.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    bulletFrame=1;
    setPixmap(QPixmap(":/images/bullet.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);

    QTimer * timerTwo = new QTimer(this);
    connect(timerTwo,SIGNAL(timeout()),this,SLOT(changeImage()));
    timerTwo->start(20);

    boomSound = new QMediaPlayer();
    boomSound->setMedia(QUrl("qrc:/sound/boom.mp3"));
    boomSound->setVolume(game->explosionVolume);
}

void Bullet::move()
{
    if(game->gameMode!="twoPlayersMode")
    {
        if(game->health->gameOverState() && game->isGamePaused==false)
            setPos(x(),y()-5);
    }
    else if(game->gameMode=="twoPlayersMode")
    {
        if(game->isGamePaused==false)
            setPos(x(),y()-8);
    }


    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i=0, n = colliding_items.size(); i<n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            if(playerOneBullet)
                game->score->increase();
            else
                game->scoreTwo->increase();

            game->lvl->enemyDestroyed();
            if(game->lvl->enemysToDestroy<=0)
                game->lvl->lvlUp();

            if(boomSound->state() == QMediaPlayer::PlayingState)
                boomSound->setPosition(0);
            else if (boomSound->state() == QMediaPlayer::StoppedState)
                boomSound->play();

            Boom * boomImage = new Boom();
            boomImage->setPos(colliding_items[i]->x()-20,colliding_items[i]->y());
            scene()->addItem(boomImage);

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
    }

    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "pocisk usuniety";
    }
}
void Bullet::changeImage()
{
    if(bulletFrame==1)
    {
        setPixmap(QPixmap(":/images/bullet2.png"));
        bulletFrame+=1;
    }
    else if(bulletFrame==2)
    {
        setPixmap(QPixmap(":/images/bullet3.png"));
        bulletFrame+=1;
    }
    else if(bulletFrame==3)
    {
        setPixmap(QPixmap(":/images/bullet4.png"));
        bulletFrame+=1;
    }
    else if(bulletFrame==4)
    {
        setPixmap(QPixmap(":/images/bullet5.png"));
        bulletFrame+=1;
    }
    else if(bulletFrame==5)
    {
        setPixmap(QPixmap(":/images/bullet6.png"));
        bulletFrame+=1;
    }
    else if(bulletFrame==6)
    {
        setPixmap(QPixmap(":/images/bullet.png"));
        bulletFrame=1;
    }
}
