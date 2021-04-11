#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsTextItem>
#include <QTimer>

class Levels: public QGraphicsTextItem
{
    Q_OBJECT

    public:
        Levels(QGraphicsItem * parent=0);
        int lvl;
        int enemyAmaount;
        int enemysToDestroy;
        void lvlUp();
        void setLvl(int rank);
        void enemyDecrease();
        void enemyDestroyed();
        void levelSign();
        void lvlParametters();
        QGraphicsTextItem* levelTransisiotn;\
        QTimer * timer;
    public slots:
        void move();
};

#endif // LEVELS_H
