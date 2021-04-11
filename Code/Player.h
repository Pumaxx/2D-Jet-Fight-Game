#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "Panel.h"


class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Player(QGraphicsItem * parent=0);
        void keyPressEvent(QKeyEvent * event);
        Panel * pausePanel;
        QMediaPlayer * bulletSound;
    public slots:
        void spawn();     
};

#endif // PLAYER_Hw
