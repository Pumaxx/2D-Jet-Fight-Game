#ifndef BOOM_H
#define BOOM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Boom: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Boom(QGraphicsItem * parent=0);
        int boomFrame;
    public slots:
        void exposion();
        void changeImage();
};

#endif // BOOM_H
