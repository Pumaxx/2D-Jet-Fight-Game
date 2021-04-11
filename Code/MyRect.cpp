#include "MyRect.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
            if(pos().x() > 0)
                setPos(x()-10,y());
        }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
            if(pos().x() + 100 < 1000 )
             setPos(x()+10,y());
        }
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
           if(pos().y() > 0)
                 setPos(x(),y()-10);
        }
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
            if(pos().y() +100 < 700)
                setPos(x(),y()+10);
        }
    else if (event->key() == Qt::Key_Space){
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+50,y()-50);
            scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
