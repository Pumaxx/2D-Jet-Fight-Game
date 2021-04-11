#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){

    setRect(0,0,400,80);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    text->setFont(QFont("Sans Serif",14));
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);
}
