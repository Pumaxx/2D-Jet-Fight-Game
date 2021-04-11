#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    public:
        Button(QString name, QGraphicsItem* parent=NULL);

        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
        QGraphicsTextItem* text;
        QMediaPlayer* clickSound;
    signals:
        void clicked();

};

#endif // BUTTON_H
