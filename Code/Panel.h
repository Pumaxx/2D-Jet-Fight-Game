#ifndef PANEL_H
#define PANEL_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QtSql>
#include "Button.h"

class Panel: public QGraphicsTextItem
{
    Q_OBJECT

    public:
        Panel(QGraphicsItem * parent=0);
        ~Panel();
        QGraphicsRectItem* panelOne;
        QGraphicsRectItem* panelTwo;
        QGraphicsTextItem* pauseTitle;
        Button* resume;
        Button* playAgain;
        Button* saveAndQuit;
        Button* closeGame;
        QSqlDatabase dataBase;
    public slots:
        void resumeGame();
        void restartGame();
        void menuButton();

};

#endif // PANEL_H
