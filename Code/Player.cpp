#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sound/bullet.mp3"));
    bulletSound->setVolume(game->shootVolume);

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(game->gameMode!="twoPlayersMode")
    {
        if(game->health->gameOverState())
        {
            if(game->isGamePaused==false)
            {
                if (event->key() == Qt::Key_A)
                {
                    if(pos().x() > 0)
                        setPos(x()-30,y());
                }
                else if (event->key() == Qt::Key_D)
                {
                    if(game->gameMode=="twoPlayersMode")
                    {
                        if(pos().x() + 125 < 959)
                            setPos(x()+30,y());
                    }
                    else
                    {
                        if(pos().x() + 125 < 1920)
                            setPos(x()+30,y());
                    }

                }
                else if (event->key() == Qt::Key_Space)
                {
                    Bullet * bullet = new Bullet();
                    bullet->setPos(x()+35,y()-5);
                    bullet->playerOneBullet=true;
                    scene()->addItem(bullet);

                    if(bulletSound->state() == QMediaPlayer::PlayingState)
                        bulletSound->setPosition(0);
                    else if (bulletSound->state() == QMediaPlayer::StoppedState)
                        bulletSound->play();
                }
            }

            if (event->key() == Qt::Key_Escape)
                game->close();

            else if (event->key() == Qt::Key_P)
            {
                if(game->isGamePaused==false)
                {
                    pausePanel = new Panel();
                    game->isGamePaused=true;
                }
                else
                {
                    delete pausePanel;
                    game->isGamePaused=false;
                }
            }
        }
    }
    else if (game->gameMode=="twoPlayersMode")
    {
        if(game->health->gameOverState())
        {
            if(game->isGamePaused==false)
            {
                if (event->key() == Qt::Key_A)
                {
                    if(pos().x() > 0)
                        setPos(x()-30,y());
                }
                else if (event->key() == Qt::Key_D)
                {
                    if(pos().x() + 125 < 959)
                        setPos(x()+30,y());
                }
                else if (event->key() == Qt::Key_Space)
                {
                    Bullet * bullet = new Bullet();
                    bullet->setPos(x()+35,y()-5);
                    bullet->playerOneBullet=true;
                    scene()->addItem(bullet);

                    if(bulletSound->state() == QMediaPlayer::PlayingState)
                        bulletSound->setPosition(0);
                    else if (bulletSound->state() == QMediaPlayer::StoppedState)
                        bulletSound->play();
                }
            }
        }
        if(game->healthTwo->gameOverState())
        {
            if(game->isGamePaused==false)
            {
                if (event->key() == Qt::Key_Left)
                {
                    if(game->playerTwo->pos().x() > 960)
                        game->playerTwo->setPos( game->playerTwo->x()-30, game->playerTwo->y());
                }
                else if (event->key() == Qt::Key_Right)
                {
                    if(game->playerTwo->pos().x() + 125 < 1920 )
                        game->playerTwo->setPos( game->playerTwo->x()+30, game->playerTwo->y());
                }
                else if (event->key() == Qt::Key_Shift)
                {
                    Bullet * bulletTwo = new Bullet();
                    bulletTwo->setPos(game->playerTwo->x()+35,game->playerTwo->y()-5);
                    bulletTwo->playerOneBullet=false;
                    scene()->addItem(bulletTwo);

                    if(bulletSound->state() == QMediaPlayer::PlayingState)
                        bulletSound->setPosition(0);
                    else if (bulletSound->state() == QMediaPlayer::StoppedState)
                        bulletSound->play();
                 }
               }
        }
        if (event->key() == Qt::Key_Escape)
            game->close();

        else if (event->key() == Qt::Key_P)
        {
            if(game->isGamePaused==false)
            {
                pausePanel = new Panel();
                game->isGamePaused=true;
            }
            else
            {
                delete pausePanel;
                game->isGamePaused=false;
            }
        }
    }
}

void Player::spawn()
{
    if(game->gameMode!="twoPlayersMode")
    {
        if(game->health->gameOverState() && game->isGamePaused==false && game->lvl->enemyAmaount > 0)
        {
            Enemy * enemy = new Enemy();
            scene()->addItem(enemy);
            game->lvl->enemyDecrease();
        }
    }
    else if(game->gameMode=="twoPlayersMode")
    {
        if(game->isGamePaused==false && game->lvl->enemyAmaount > 0)
        {
            if(game->health->gameOverState() || game->healthTwo->gameOverState())
            {
                Enemy * enemy = new Enemy();
                scene()->addItem(enemy);
                game->lvl->enemyDecrease();
            }
        }
    }
}
