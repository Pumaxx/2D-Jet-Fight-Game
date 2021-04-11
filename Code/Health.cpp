#include <QFont>
#include <QGraphicsScene>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>
#include "Health.h"
#include "Game.h"
#include "Score.h"
#include "Button.h"

extern Game * game;
extern Score * score;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 100;

    setPlainText(QString("Health: ") + QString::number(health) + QString("%"));
    setDefaultTextColor(Qt::darkGreen);
    setFont(QFont("times",25, QFont::Bold));

    gameOverSound = new QMediaPlayer();
    gameOverSound->setMedia(QUrl("qrc:/sound/Game_Over.mp3"));
    gameOverSound->setVolume(100);
}
void Health::decrease()
{
    health-=33;
    setPlainText(QString("Health: ") + QString::number(health) + QString("%"));

    if(game->gameMode=="twoPlayersMode")
    {
        if(isPlayerOneHealth && health <0)
        {
            setPlainText(QString("Health: 0%"));
            drawGameOver(0,0,960,1080,Qt::black,0.70);
            drawGameOver(192,0,576,1080,Qt::black,0.70);

            gameOverTextOne = new QGraphicsTextItem();
            gameOverTextOne->setPlainText(QString("GAME OVER"));
            gameOverTextOne->setDefaultTextColor(Qt::red);
            gameOverTextOne->setPos(game->scene->width()/4-185, game->scene->height()/10-25);
            gameOverTextOne-> setFont(QFont("times",45, QFont::Bold));
            game->scene->addItem(gameOverTextOne);

            endGameScoreOne = new QGraphicsTextItem();
            endGameScoreOne->setPlainText(QString("Your Score: ") + QString::number(game->score->getScore()));
            endGameScoreOne->setDefaultTextColor(Qt::blue);
            endGameScoreOne->setPos(game->scene->width()/4-150, game->scene->height()/10+75);
            endGameScoreOne->setFont(QFont("times",35, QFont::Bold));
            game->scene->addItem(endGameScoreOne);

            game->playerOneNoHp=true;
        }
        else if(!isPlayerOneHealth && health <0)
        {
            setPlainText(QString("Health: 0%"));
            drawGameOver(960,0,960,1080,Qt::black,0.70);
            drawGameOver(1152,0,576,1080,Qt::black,0.70);

            gameOverText = new Health();
            gameOverText->setPlainText(QString("GAME OVER"));
            gameOverText->setPos(3*game->scene->width()/4-185, game->scene->height()/10-25);
            gameOverText-> setFont(QFont("times",45, QFont::Bold));
            game->scene->addItem(gameOverText);

            endGameScore = new Score();
            endGameScore->setPlainText(QString("Your Score: ") + QString::number(game->scoreTwo->getScore()));
            endGameScore->setPos(3*game->scene->width()/4-150, game->scene->height()/10+75);
            endGameScore->setFont(QFont("times",35, QFont::Bold));
            game->scene->addItem(endGameScore);

            game->playerTwoNoHp=true;
        }
        if(game->playerOneNoHp && game->playerTwoNoHp)
        {
            game->backgroundMusic->setVolume(5);
            gameOverSound->play();

            drawGameOver(192,0,1536,1080,Qt::black,1);

            gameOverText = new Health();

            if(game->score->getScore() > game->scoreTwo->getScore())
                gameOverText->setPlainText("Player One");
            else if(game->score->getScore() < game->scoreTwo->getScore())
                gameOverText->setPlainText("Player Two");
            else
                gameOverText->setPlainText("Good Match");

            gameOverText->setPos(game->scene->width()/2-285, game->scene->height()/10-25);
            gameOverText->setDefaultTextColor(Qt::lightGray);
            gameOverText-> setFont(QFont("times",75, QFont::Bold));
            game->scene->addItem(gameOverText);

            endGameScore = new Score();

            if(game->score->getScore() == game->scoreTwo->getScore())
                endGameScore->setPlainText("DRAW");
            else
                endGameScore->setPlainText("WINS");

            endGameScore->setDefaultTextColor(Qt::darkGreen);
            endGameScore->setPos(game->scene->width()/2-200, game->scene->height()/10+100);
            endGameScore->setFont(QFont("times",85, QFont::Bold));
            game->scene->addItem(endGameScore);

            Button* playAgain = new Button(QString("Play Again"));
            playAgain->setPos(game->scene->width()/2-225,705);
            game->scene->addItem(playAgain);
            connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGamee()));

            Button* menu = new Button(QString("Menu"));
            menu->setPos(game->scene->width()/2-225,800);
            game->scene->addItem(menu);
            connect(menu,SIGNAL(clicked()),this,SLOT(menuButton()));

            Button* closeGame = new Button(QString("Close Game"));
            closeGame->setPos(game->scene->width()/2-225,915);
            game->scene->addItem(closeGame);
            connect(closeGame,SIGNAL(clicked()),game,SLOT(close()));
        }
    }

    else if(health <0)
    {
        setPlainText(QString("Health: 0%"));

        game->backgroundMusic->setVolume(5);
        gameOverSound->play();

        drawGameOver(0,0,1920,1080,Qt::black,0.70);
        drawGameOver(384,0,1152,1080,Qt::black,0.70);
        putScoreToDatabase();

        gameOverText = new Health();
        gameOverText->setPlainText(QString("GAME OVER"));
        gameOverText->setPos(game->scene->width()/2-285, game->scene->height()/10-25);
        gameOverText-> setFont(QFont("times",65, QFont::Bold));
        game->scene->addItem(gameOverText);

        endGameScore = new Score();
        endGameScore->setPlainText(QString("Your Score: ") + QString::number(game->score->getScore()));
        endGameScore->setPos(game->scene->width()/2-250, game->scene->height()/10+75);
        endGameScore->setFont(QFont("times",55, QFont::Bold));
        game->scene->addItem(endGameScore);

        QString scoresTable="Rank\t\t\tScore\n";

        for(int i=0;i<3;i++)
        {
            if(i==0)
                 scoresTable+=QString::number(i+1)+"st\t\t\t\t"+highScoresTable[i]+"\n";
            else if(i==1)
                scoresTable+=QString::number(i+1)+"nd\t\t\t"+highScoresTable[i]+"\n";
            else if(i==2)
                scoresTable+=QString::number(i+1)+"rd\t\t\t"+highScoresTable[i]+"\n";
            else if(3<=i && i<=8)
                scoresTable+=QString::number(i+1)+"th\t\t\t"+highScoresTable[i]+"\n";
            else
                scoresTable+=QString::number(i+1)+"th\t\t"+highScoresTable[i]+"\n";
        }

        highScoreOne = new Score();
        highScoreOne->setPlainText(scoresTable);
        highScoreOne->setPos(game->scene->width()/2-240, game->scene->height()/3-5);
        highScoreOne->setDefaultTextColor(Qt::yellow);
        highScoreOne->setFont(QFont("times",40, QFont::Bold));
        game->scene->addItem(highScoreOne);

        Button* playAgain = new Button(QString("Play Again"));
        playAgain->setPos(game->scene->width()/2-225,705);
        game->scene->addItem(playAgain);
        connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGamee()));

        Button* menu = new Button(QString("Menu"));
        menu->setPos(game->scene->width()/2-225,800);
        game->scene->addItem(menu);
        connect(menu,SIGNAL(clicked()),this,SLOT(menuButton()));

        Button* closeGame = new Button(QString("Close Game"));
        closeGame->setPos(game->scene->width()/2-225,915);
        game->scene->addItem(closeGame);
        connect(closeGame,SIGNAL(clicked()),game,SLOT(close()));

    }
}
void Health::putScoreToDatabase()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    if(game->gameMode=="classicMode")
        dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/classicModeScores.db");
    else if(game->gameMode=="arcadeMode")
        dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/arcadeModeScores .db");

    if(!dataBase.open())
        qDebug() << "Database open error";

    QSqlQuery qry;
    qry.prepare("INSERT INTO Scores (PlayerScore) VALUES (?);");
    qry.addBindValue(game->score->getScore());
    qry.exec();

    QSqlQuery query("SELECT PlayerScore FROM Scores ORDER BY PlayerScore DESC");
    int idScore = query.record().indexOf("PlayerScore");

    for(int i=0;i<3;i++)
    {
        query.next();
        highScoresTable[i] = query.value(idScore).toString();
        qDebug() << highScoresTable[i];
    }

    dataBase.close();
}
void Health::drawGameOver(int xStart, int yStart, int width, int height,QColor color, double opacity)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(xStart,yStart,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    game->scene->addItem(panel);
}

int Health::getHealth()
{
    return health;
}

bool Health::gameOverState()
{
    if(health < 0)
        return false;
    else
        return true;
}
bool Health::gameOverStateTwo()
{
    if(health < 0 && !isPlayerOneHealth)
        return false;
    else if (!isPlayerOneHealth)
        return true;
}

void Health::restartGamee()
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

void Health::menuButton()
{
    qDeleteAll(scene()->items());
    game->menu();
}
