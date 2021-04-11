#include <QFont>
#include <QTimer>
#include "Panel.h"
#include "Game.h"
#include "Button.h"

extern Game * game;

Panel::Panel(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    QBrush brush;

    panelOne = new QGraphicsRectItem(0,0,1920,1080);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panelOne->setBrush(brush);
    panelOne->setOpacity(0.70);

    panelTwo = new QGraphicsRectItem(384,0,1152,1080);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panelTwo->setBrush(brush);
    panelTwo->setOpacity(0.70);

    game->scene->addItem(panelOne);
    game->scene->addItem(panelTwo);

    pauseTitle = new QGraphicsTextItem("Pause");
    pauseTitle->setFont(QFont("times",105, QFont::Bold, true));
    pauseTitle->setDefaultTextColor(Qt::yellow);
    pauseTitle->setPos(game->scene->width()/2-180,80);
    game->scene->addItem(pauseTitle);


    resume = new Button(QString("Resume"));
    resume->setPos(game->scene->width()/2-225,595);
    game->scene->addItem(resume);
    connect(resume,SIGNAL(clicked()),this,SLOT(resumeGame()));

    playAgain = new Button(QString("Restart"));
    playAgain->setPos(game->scene->width()/2-225,690);
    game->scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    if(game->gameMode=="classicMode")
       saveAndQuit = new Button(QString("Save & Menu"));
    else
       saveAndQuit = new Button(QString("Menu"));
    saveAndQuit->setPos(game->scene->width()/2-225,785);
    game->scene->addItem(saveAndQuit);
    connect(saveAndQuit,SIGNAL(clicked()),this,SLOT(menuButton()));

    closeGame = new Button(QString("Close Game"));
    closeGame->setPos(game->scene->width()/2-225,915);
    game->scene->addItem(closeGame);
    connect(closeGame,SIGNAL(clicked()),game,SLOT(close()));
}
Panel::~Panel()
{
    game->scene->removeItem(panelTwo);
    game->scene->removeItem(panelOne);
    game->scene->removeItem(pauseTitle);
    game->scene->removeItem(resume);
    game->scene->removeItem(playAgain);
    game->scene->removeItem(saveAndQuit);
    game->scene->removeItem(closeGame);
}
void Panel::resumeGame()
{
    game->isGamePaused=false;
    delete this;
    game->player->setFocus();
}
void Panel::restartGame()
{
    game->isGamePaused=false;
    qDeleteAll(game->scene->items());

    if(game->gameMode=="twoPlayersMode")
        game->startGameTwoPlayers();
    else if(game->gameMode=="arcadeMode")
    {
        game->startGame();
        game->lvl->setLvl(game->lvlChosen);
    }
    else
        game->startGame();
}
void Panel::menuButton()
{
    if(game->gameMode=="classicMode")
    {
        dataBase = QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/ClassicModeSave.db");


        if(!dataBase.open())
            qDebug() << "Database open error";

        QSqlQuery qry;
        qry.prepare("UPDATE Saves SET Score=?,Level=?  WHERE SaveID=1;");
        qry.addBindValue(game->curentScore);
        qry.addBindValue(game->lvl->lvl);
        qry.exec();

        dataBase.close();
    }

    qDeleteAll(game->scene->items());
    game->menu();
    game->isGamePaused=false;
}

