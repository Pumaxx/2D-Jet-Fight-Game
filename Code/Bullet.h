#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Bullet(QGraphicsItem * parent=0);
        bool playerOneBullet;
        QMediaPlayer * boomSound;
        int bulletFrame;
    public slots:
        void move();
        void changeImage();
};

#endif // BULLET_H
