#include <QFont>
#include <QTimer>
#include "Levels.h"
#include "Game.h"

extern Game * game;

Levels::Levels(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    if(game->gameMode!="twoPlayersMode")
    {
        lvl = 1;
        enemyAmaount = 10;
        enemysToDestroy = enemyAmaount;

        if(game->gameMode=="classicMode")
            setPlainText(QString("Level: ") + QString::number(lvl));
        else
        {
            if(lvl>10)
                setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: inf");
            else
                setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: "+QString::number(enemysToDestroy));
        }

        setDefaultTextColor(Qt::darkBlue);
        setFont(QFont("times",25, QFont::Bold));

        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    }
    else if(game->gameMode=="twoPlayersMode")
    {
        lvl = 1;
        enemyAmaount = 2147483646;
        enemysToDestroy = enemyAmaount;
    }
}
void Levels::enemyDecrease()
{
    enemyAmaount -= 1;

    if(game->gameMode=="classicMode")
        setPlainText(QString("Level: ") + QString::number(lvl));
    else
    {
        if(lvl>10)
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: inf");
        else
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: "+QString::number(enemysToDestroy));
    }
}
void Levels::enemyDestroyed()
{
    enemysToDestroy -= 1;

    if(game->gameMode=="classicMode")
        setPlainText(QString("Level: ") + QString::number(lvl));
    else
    {
        if(lvl>10)
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: inf");
        else
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: "+QString::number(enemysToDestroy));
    }
}
void Levels::lvlUp()
{
    game->curentScore=game->score->getScore();
    game->timer->stop();
    lvl+=1;

    if(lvl>10)
        enemyAmaount = 2147483646;
    else
        enemyAmaount = (lvl+1)*5;

    enemysToDestroy = enemyAmaount;

    if(game->gameMode=="classicMode")
        setPlainText(QString("Level: ") + QString::number(lvl));
    else
    {
        if(lvl>10)
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: inf");
        else
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: "+QString::number(enemysToDestroy));
    }
    levelSign();
}
void Levels::setLvl(int rank)
{
    lvl=rank;

    if(lvl>10)
        enemyAmaount = 2147483646;
    else
        enemyAmaount = (lvl+1)*5;

    enemysToDestroy = enemyAmaount;

    if(game->gameMode=="classicMode")
        setPlainText(QString("Level: ") + QString::number(lvl));
    else
    {
        if(lvl>10)
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: inf");
        else
            setPlainText(QString("Level: ") + QString::number(lvl)+"\nTo destroy: "+QString::number(enemysToDestroy));
    }


    lvlParametters();
}

void Levels::levelSign()
{
    if(lvl>10)
        levelTransisiotn = new QGraphicsTextItem("ENDLESS\n  MODE");
    else
        levelTransisiotn = new QGraphicsTextItem("LEVEL "+ QString::number(lvl));

    levelTransisiotn->setFont(QFont("Times New Roman",100, QFont::Bold, true));
    levelTransisiotn->setDefaultTextColor(Qt::darkBlue);
    levelTransisiotn->setPos(-525, game->scene->height()/2-100);
    game->scene->addItem(levelTransisiotn);

    timer->start(2);
}
void Levels::move()
{

    if(game->isGamePaused==false)
        levelTransisiotn->setPos(levelTransisiotn->x()+1,levelTransisiotn->y());

     if(levelTransisiotn->pos().x() == 1400)
     {
        lvlParametters();
     }

     else if (levelTransisiotn->pos().x() > 1920)
     {
         game->scene->removeItem(levelTransisiotn);
         timer->stop();
         delete levelTransisiotn;
     }
}
void Levels::lvlParametters()
{
    if(lvl>1&& lvl<3)
    {
        game->timer->start(900);
        game->enemySpeed=2;
    }
    else if(lvl>2 && lvl<5)
    {
        game->timer->start(870);
        game->enemySpeed=2;
    }
    else if(lvl>4 && lvl<7)
    {
        game->timer->start(845);
        game->enemySpeed=3;
    }
    else if(lvl>6 && lvl<9)
    {
        game->timer->start(825);
        game->enemySpeed=3;
    }
    else if(lvl>8 && lvl<11)
    {
        game->timer->start(810);
        game->enemySpeed=4;
    }
    else if(lvl>10)
    {
        game->timer->start(800);
        game->enemySpeed=4;
    }
}
