#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Enemy: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Enemy(QGraphicsItem * parent=0);
        QMediaPlayer * boomSound;
    public slots:
        void move();
};

#endif // ENEMY_H
