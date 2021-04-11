#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Levels.h"
#include "Panel.h"
#include "Menu.h"
#include "Enemy.h"
#include "Bullet.h"

class Game: public QGraphicsView
{
    public:
        Game(QWidget * parent=0);

        QGraphicsScene * scene;
        Menu * menuPanel;
        Player * player;
        Player * playerTwo;
        Score * score;
        Score * scoreTwo;
        Health * health;
        Health * healthTwo;
        Levels * lvl;
        Enemy * enemy;
        Bullet * bullet;
        QMediaPlayer * backgroundMusic;
        QTimer * timer;
        QString gameMode;
        bool isGamePaused;
        bool playerOneNoHp;
        bool playerTwoNoHp;
        int lvlChosen;
        int enemySpeed;
        int curentScore;
        int backgroundVolume;
        int explosionVolume;
        int shootVolume;
        void startGame();
        void startGameTwoPlayers();
        void menu();
};

#endif // GAME_H
