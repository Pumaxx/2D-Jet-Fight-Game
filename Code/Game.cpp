#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <QMediaPlayer>
#include <QPainter>
#include <QDebug>
#include "Enemy.h"
#include "Game.h"
#include "Menu.h"

Game::Game(QWidget *parent)
{
    backgroundVolume=15;
    explosionVolume=60;
    shootVolume=45;

    isGamePaused = false;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080);
    showFullScreen();
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    backgroundMusic = new QMediaPlayer();
    backgroundMusic->setMedia(QUrl("qrc:/sound/bg.mp3"));
    backgroundMusic->setVolume(backgroundVolume);
    backgroundMusic->play();

    if (backgroundMusic->state() == QMediaPlayer::StoppedState)
        backgroundMusic->play();

    show();
}

void Game::menu()
{
    menuPanel = new Menu();
}

void Game::startGame()
{
    enemySpeed=2;
    curentScore=0;

    player = new Player();
    player->setPixmap(QPixmap(":/images/player.png"));
    player->setPos(scene->width()/2-63, scene->height()-scene->height()/10-15);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    score->setPos(score->x()+5,score->y()+10);
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+5,health->y()+50);
    health->isPlayerOneHealth=true;
    scene->addItem(health);

    lvl = new Levels();
    lvl->setPos(lvl->x()+5,lvl->y()+90);
    scene->addItem(lvl);

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(950);
}

void Game::startGameTwoPlayers()
{
    playerOneNoHp=false;
    playerTwoNoHp=false;

    QBrush brush;
    QGraphicsRectItem* line = new QGraphicsRectItem(959,0,2,1080);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    line->setBrush(brush);
    line->setOpacity(1);
    scene->addItem(line);

    player = new Player();
    player->setPixmap(QPixmap(":/images/player.png"));
    player->setPos(scene->width()/4-100, scene->height()-scene->height()/10-15);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    playerTwo = new Player();
    playerTwo->setPixmap(QPixmap(":/images/player.png"));
    playerTwo->setPos(3*scene->width()/4-50, scene->height()-scene->height()/10-15);
    scene->addItem(playerTwo);

    score = new Score();
    score->setPos(score->x()+5,score->y()+10);
    scene->addItem(score);

    scoreTwo = new Score();
    scoreTwo->setPos(scoreTwo->x()+965,scoreTwo->y()+10);
    scene->addItem(scoreTwo);

    health = new Health();
    health->setPos(health->x()+5,health->y()+50);
    health->isPlayerOneHealth=true;
    scene->addItem(health);

    healthTwo = new Health();
    healthTwo->setPos(healthTwo->x()+965,healthTwo->y()+50);
    healthTwo->isPlayerOneHealth=false;
    scene->addItem(healthTwo);

    lvl = new Levels();

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(700);
}
