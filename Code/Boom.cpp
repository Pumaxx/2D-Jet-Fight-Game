#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include "Boom.h"

extern Game * game;

Boom::Boom(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    boomFrame=1;
    setPixmap(QPixmap(":/images/boom.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(exposion()));
    timer->start(650);

    QTimer * timerTwo = new QTimer(this);
    connect(timerTwo,SIGNAL(timeout()),this,SLOT(changeImage()));
    timerTwo->start(25);
}

void Boom::exposion()
{
    scene()->removeItem(this);
    delete this;
}
void Boom::changeImage()
{
    if(boomFrame==1)
    {
        setPixmap(QPixmap(":/images/boom2.png"));
        boomFrame+=1;
    }
    else if(boomFrame==2)
    {
        setPixmap(QPixmap(":/images/boom3.png"));
        boomFrame+=1;
    }
    else if(boomFrame==3)
    {
        setPixmap(QPixmap(":/images/boom4.png"));
        boomFrame+=1;
    }
    else if(boomFrame==4)
    {
        setPixmap(QPixmap(":/images/boom5.png"));
        boomFrame+=1;
    }
    else if(boomFrame==5)
    {
        setPixmap(QPixmap(":/images/boom6.png"));
        boomFrame+=1;
    }
    else if(boomFrame==6)
    {
        setPixmap(QPixmap(":/images/boom7.png"));
        boomFrame+=1;
    }
    else if(boomFrame==7)
    {
        setPixmap(QPixmap(":/images/boom8.png"));
        boomFrame+=1;
    }
    else if(boomFrame==8)
    {
        setPixmap(QPixmap(":/images/boom9.png"));
        boomFrame+=1;
    }
    else if(boomFrame==9)
    {
        setPixmap(QPixmap(":/images/boom10.png"));
        boomFrame+=1;
    }
    else if(boomFrame==10)
    {
        setPixmap(QPixmap(":/images/boom11.png"));
        boomFrame+=1;
    }
    else if(boomFrame==11)
    {
        setPixmap(QPixmap(":/images/boom12.png"));
        boomFrame+=1;
    }
    else if(boomFrame==12)
    {
        setPixmap(QPixmap(":/images/boom13.png"));
        boomFrame+=1;
    }
    else if(boomFrame==13)
    {
        setPixmap(QPixmap(":/images/boom14.png"));
        boomFrame+=1;
    }
    else if(boomFrame==14)
    {
        setPixmap(QPixmap(":/images/boom15.png"));
        boomFrame+=1;
    }
    else if(boomFrame==15)
    {
        setPixmap(QPixmap(":/images/boom16.png"));
        boomFrame+=1;
    }
    else if(boomFrame==16)
    {
        setPixmap(QPixmap(":/images/boom17.png"));
        boomFrame+=1;
    }
    else if(boomFrame==17)
    {
        setPixmap(QPixmap(":/images/boom18.png"));
        boomFrame+=1;
    }
    else if(boomFrame==18)
    {
        setPixmap(QPixmap(":/images/boom19.png"));
        boomFrame+=1;
    }
    else if(boomFrame==19)
    {
        setPixmap(QPixmap(":/images/boom20.png"));
        boomFrame+=1;
    }
    else if(boomFrame==20)
    {
        setPixmap(QPixmap(":/images/boom21.png"));
        boomFrame+=1;
    }
    else if(boomFrame==21)
    {
        setPixmap(QPixmap(":/images/boom22.png"));
        boomFrame+=1;
    }
    else if(boomFrame==22)
    {
        setPixmap(QPixmap(":/images/boom23.png"));
        boomFrame+=1;
    }
    else if(boomFrame==23)
    {
        setPixmap(QPixmap(":/images/boom.png"));
        boomFrame=1;
    }
}
