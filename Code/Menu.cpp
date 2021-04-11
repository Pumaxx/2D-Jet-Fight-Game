#include <QFont>
#include <QTimer>
#include <QLineEdit>
#include "Menu.h"
#include "Game.h"
#include "Button.h"

extern Game * game;

Menu::Menu(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    QBrush brush;

    game->gameMode="classicMode";
    game->lvlChosen=1;
    highScoreType="classicMode";

    panelOne = new QGraphicsRectItem(0,0,1920,1080);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGreen);
    panelOne->setBrush(brush);
    panelOne->setOpacity(0.50);

    panelTwo = new QGraphicsRectItem(384,0,1152,1080);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panelTwo->setBrush(brush);
    panelTwo->setOpacity(0.70);

    menuTitle = new QGraphicsTextItem("Menu");
    menuTitle->setFont(QFont("times",105, QFont::Bold, true));
    menuTitle->setDefaultTextColor(Qt::yellow);
    menuTitle->setPos(game->scene->width()/2-180,80);   

    classicMode = new Button(QString("Classic Mode"));
    classicMode->setPos(game->scene->width()/2-225,365); 
    connect(classicMode,SIGNAL(clicked()),this,SLOT(classicModeButton()));

    arcadeMode = new Button(QString("Arcade Mode"));
    arcadeMode->setPos(game->scene->width()/2-225,460);
    connect(arcadeMode,SIGNAL(clicked()),this,SLOT(arcadeModeButton()));

    twoPlayersMode = new Button(QString("Two Players"));
    twoPlayersMode->setPos(game->scene->width()/2-225,555);
    connect(twoPlayersMode,SIGNAL(clicked()),this,SLOT(twoPlayersModeButton()));

    highScores = new Button(QString("High Scores"));
    highScores->setPos(game->scene->width()/2-225,690);
    connect(highScores,SIGNAL(clicked()),this,SLOT(highScoresButton()));

    options = new Button(QString("Options"));
    options->setPos(game->scene->width()/2-225,785);
    connect(options,SIGNAL(clicked()),this,SLOT(optionButton()));

    closeGame = new Button(QString("Close Game"));
    closeGame->setPos(game->scene->width()/2-225,915);
    connect(closeGame,SIGNAL(clicked()),game,SLOT(close()));

    createMenu();

    gameModeModeTitle = new QGraphicsTextItem();
    gameModeModeTitle->setDefaultTextColor(Qt::yellow);

    highScoreDisplay = new QGraphicsTextItem();
    highScoreDisplay->setDefaultTextColor(Qt::white);
    highScoreDisplay->setFont(QFont("times",28, QFont::Bold));

    volumeDisplay = new QGraphicsTextItem();
    volumeDisplay->setDefaultTextColor(Qt::white);
    volumeDisplay->setFont(QFont("times",33, QFont::Bold));

    startGame = new Button(QString("Start Game"));

    loadGame = new Button(QString("Load Game"));
    loadGame->setPos(game->scene->width()/2-225,785);

    backToMenu = new Button(QString("Back"));
    backToMenu->setPos(game->scene->width()/2-225,915);

    highScoreChange = new Button(QString("Aracde Mode"));
    highScoreChange->setPos(game->scene->width()/2-225,820);

    backgroundVolumIncreasee = new Button(QString(">"));
    backgroundVolumIncreasee->setPos(game->scene->width()/2+300,405);
    backgroundVolumIncreasee->setRect(0,0,50,50);
    backgroundVolumIncreasee->text->setPos(backgroundVolumIncreasee->rect().width()/2 - backgroundVolumIncreasee->text->boundingRect().width()/2,backgroundVolumIncreasee->rect().height()/2 - backgroundVolumIncreasee->text->boundingRect().height()/2);

    backgroundVolumDecrease = new Button(QString("<"));
    backgroundVolumDecrease->setPos(game->scene->width()/2+125,405);
    backgroundVolumDecrease->setRect(0,0,50,50);
    backgroundVolumDecrease->text->setPos(backgroundVolumDecrease->rect().width()/2 - backgroundVolumDecrease->text->boundingRect().width()/2,backgroundVolumDecrease->rect().height()/2 - backgroundVolumDecrease->text->boundingRect().height()/2);

    explosiondVolumIncreasee = new Button(QString(">"));
    explosiondVolumIncreasee->setPos(game->scene->width()/2+300,510);
    explosiondVolumIncreasee->setRect(0,0,50,50);
    explosiondVolumIncreasee->text->setPos(explosiondVolumIncreasee->rect().width()/2 - explosiondVolumIncreasee->text->boundingRect().width()/2,explosiondVolumIncreasee->rect().height()/2 - explosiondVolumIncreasee->text->boundingRect().height()/2);

    explosionVolumDecrease = new Button(QString("<"));
    explosionVolumDecrease->setPos(game->scene->width()/2+125,510);
    explosionVolumDecrease->setRect(0,0,50,50);
    explosionVolumDecrease->text->setPos(explosionVolumDecrease->rect().width()/2 - explosionVolumDecrease->text->boundingRect().width()/2,explosionVolumDecrease->rect().height()/2 - explosionVolumDecrease->text->boundingRect().height()/2);

    shootdVolumIncreasee = new Button(QString(">"));
    shootdVolumIncreasee->setPos(game->scene->width()/2+300,615);
    shootdVolumIncreasee->setRect(0,0,50,50);
    shootdVolumIncreasee->text->setPos(shootdVolumIncreasee->rect().width()/2 - shootdVolumIncreasee->text->boundingRect().width()/2,shootdVolumIncreasee->rect().height()/2 - shootdVolumIncreasee->text->boundingRect().height()/2);

    shotdVolumDecrease = new Button(QString("<"));
    shotdVolumDecrease->setPos(game->scene->width()/2+125,615);
    shotdVolumDecrease->setRect(0,0,50,50);
    shotdVolumDecrease->text->setPos(shotdVolumDecrease->rect().width()/2 - shotdVolumDecrease->text->boundingRect().width()/2,shotdVolumDecrease->rect().height()/2 - shotdVolumDecrease->text->boundingRect().height()/2);

    levelOne = new Button(QString("Level 1"));
    levelOne->setPos(game->scene->width()/2-425,385);

    levelTwo= new Button(QString("Level 2"));
    levelTwo->setPos(game->scene->width()/2-25,385);

    levelThree = new Button(QString("Level 3"));
    levelThree->setPos(game->scene->width()/2-425,465);

    levelFour = new Button(QString("Level 4"));
    levelFour->setPos(game->scene->width()/2-25,465);

    levelFive = new Button(QString("Level 5"));
    levelFive->setPos(game->scene->width()/2-25,545);

    levelSix = new Button(QString("Level 6"));
    levelSix->setPos(game->scene->width()/2-425,545);

    levelSeven = new Button(QString("Level 7"));
    levelSeven->setPos(game->scene->width()/2-425,625);

    levelEight= new Button(QString("Level 8"));
    levelEight->setPos(game->scene->width()/2-25,625);

    levelNine = new Button(QString("Level 9"));
    levelNine->setPos(game->scene->width()/2-425,705);

    levelTen = new Button(QString("Level 10"));
    levelTen->setPos(game->scene->width()/2-25,705);

    levelEndlessMode = new Button(QString("Endless mode"));
    levelEndlessMode->setRect(0,0,800,80);
    levelEndlessMode->text->setPos(levelEndlessMode->rect().width()/2 - levelEndlessMode->text->boundingRect().width()/2,levelEndlessMode->rect().height()/2 - levelEndlessMode->text->boundingRect().height()/2);
    levelEndlessMode->setPos(game->scene->width()/2-425,785);
}
Menu::~Menu()
{
    game->scene->removeItem(panelTwo);
    game->scene->removeItem(panelOne);
    removeButtons();
}
void Menu::createMenu()
{
    game->scene->addItem(panelOne);
    game->scene->addItem(panelTwo);
    game->scene->addItem(menuTitle);
    game->scene->addItem(classicMode);
    game->scene->addItem(arcadeMode);
    game->scene->addItem(twoPlayersMode);
    game->scene->addItem(highScores);
    game->scene->addItem(options);
    game->scene->addItem(closeGame);
}
void Menu::removeButtons()
{
    game->scene->removeItem(menuTitle);
    game->scene->removeItem(classicMode);
    game->scene->removeItem(arcadeMode);
    game->scene->removeItem(twoPlayersMode);
    game->scene->removeItem(highScores);
    game->scene->removeItem(options);
    game->scene->removeItem(closeGame);
    game->scene->removeItem(gameModeModeTitle);
    game->scene->removeItem(startGame);
    game->scene->removeItem(loadGame);
    game->scene->removeItem(backToMenu);
    game->scene->removeItem(highScoreChange);
    game->scene->removeItem(highScoreDisplay);
    game->scene->removeItem(volumeDisplay);
    game->scene->removeItem(levelOne);
    game->scene->removeItem(levelTwo);
    game->scene->removeItem(levelThree);
    game->scene->removeItem(levelFour);
    game->scene->removeItem(levelFive);
    game->scene->removeItem(levelSix);
    game->scene->removeItem(levelSeven);
    game->scene->removeItem(levelEight);
    game->scene->removeItem(levelNine);
    game->scene->removeItem(levelTen);
    game->scene->removeItem(levelEndlessMode);
    game->scene->removeItem(backgroundVolumIncreasee);
    game->scene->removeItem(backgroundVolumDecrease);
    game->scene->removeItem(explosiondVolumIncreasee);
    game->scene->removeItem(explosionVolumDecrease);
    game->scene->removeItem(shootdVolumIncreasee);
    game->scene->removeItem(shotdVolumDecrease);
}
void Menu::classicModeButton()
{
    game->gameMode="classicMode";
    removeButtons();

    gameModeModeTitle->setPlainText("Classic mode");
    gameModeModeTitle->setFont(QFont("times",90, QFont::Bold, true));
    gameModeModeTitle->setPos(game->scene->width()/2-350,95);
    game->scene->addItem(gameModeModeTitle);

    startGame->setPos(game->scene->width()/2-225,690);
    game->scene->addItem(startGame);
    connect(startGame,SIGNAL(clicked()),this,SLOT(startGameButton()));

    game->scene->addItem(loadGame);
    connect(loadGame,SIGNAL(clicked()),this,SLOT(loadGameButton()));

    game->scene->addItem(backToMenu);
    connect(backToMenu,SIGNAL(clicked()),this,SLOT(backButton()));
}
void Menu::arcadeModeButton()
{
    game->gameMode="arcadeMode";
    removeButtons();

    gameModeModeTitle->setPlainText("Arcade mode");
    gameModeModeTitle->setFont(QFont("times",90, QFont::Bold, true));
    gameModeModeTitle->setPos(game->scene->width()/2-350,95);
    game->scene->addItem(gameModeModeTitle);

    game->scene->addItem(levelOne);
    connect(levelOne,SIGNAL(clicked()),this,SLOT(levelOneButton()));
    game->scene->addItem(levelTwo);
    connect(levelTwo,SIGNAL(clicked()),this,SLOT(levelTwoButton()));
    game->scene->addItem(levelThree);
    connect(levelThree,SIGNAL(clicked()),this,SLOT(levelThreeButton()));
    game->scene->addItem(levelFour);
    connect(levelFour,SIGNAL(clicked()),this,SLOT(levelFourButton()));
    game->scene->addItem(levelFive);
    connect(levelFive,SIGNAL(clicked()),this,SLOT(levelFiveButton()));
    game->scene->addItem(levelSix);
    connect(levelSix,SIGNAL(clicked()),this,SLOT(levelSixButton()));
    game->scene->addItem(levelSeven);
    connect(levelSeven,SIGNAL(clicked()),this,SLOT(levelSevenButton()));
    game->scene->addItem(levelEight);
    connect(levelEight,SIGNAL(clicked()),this,SLOT(levelEightButton()));
    game->scene->addItem(levelNine);
    connect(levelNine,SIGNAL(clicked()),this,SLOT(levelNineButton()));
    game->scene->addItem(levelTen);
    connect(levelTen,SIGNAL(clicked()),this,SLOT(levelTenButton()));
    game->scene->addItem(levelEndlessMode);
    connect(levelEndlessMode,SIGNAL(clicked()),this,SLOT(levelEndlessModeButton()));

    game->scene->addItem(backToMenu);
    connect(backToMenu,SIGNAL(clicked()),this,SLOT(backButton()));
}
void Menu::twoPlayersModeButton()
{
    removeButtons();
    game->gameMode="twoPlayersMode";

    gameModeModeTitle->setPlainText("Two Players");
    gameModeModeTitle->setFont(QFont("times",90, QFont::Bold, true));
    gameModeModeTitle->setPos(game->scene->width()/2-300,95);
    game->scene->addItem(gameModeModeTitle);

    startGame->setPos(game->scene->width()/2-225,785);
    game->scene->addItem(startGame);
    connect(startGame,SIGNAL(clicked()),this,SLOT(startGameTwoPlayersButton()));

    game->scene->addItem(backToMenu);
    connect(backToMenu,SIGNAL(clicked()),this,SLOT(backButton()));
}
void Menu::highScoresButton()
{
    removeButtons();

    gameModeModeTitle->setFont(QFont("times",70, QFont::Bold, true));
    gameModeModeTitle->setPlainText("High Scores Classic");

    gameModeModeTitle->setPos(game->scene->width()/2-350,95);
    game->scene->addItem(gameModeModeTitle);

    highScoresFromDatabase();

    scoresTable="Rank\t\t\tScore\n\n";

    for(int i=0;i<10;i++)
    {
        if(i==0)
             scoresTable+=QString::number(i+1)+"st\t\t\t\t"+highScoresTable[i]+"\n";
        else if(i==1)
            scoresTable+=QString::number(i+1)+"nd\t\t\t\t"+highScoresTable[i]+"\n";
        else if(i==2)
            scoresTable+=QString::number(i+1)+"rd\t\t\t\t"+highScoresTable[i]+"\n";
        else if(3<=i && i<=8)
            scoresTable+=QString::number(i+1)+"th\t\t\t\t"+highScoresTable[i]+"\n";
        else
            scoresTable+=QString::number(i+1)+"th\t\t\t\t"+highScoresTable[i]+"\n";
    }

    highScoreDisplay->setPlainText(scoresTable);
    highScoreDisplay->setPos(game->scene->width()/2-225, 240);
    game->scene->addItem(highScoreDisplay);

    game->scene->addItem(highScoreChange);
    connect(highScoreChange,SIGNAL(clicked()),this,SLOT(highScoreChangeButton()));

    game->scene->addItem(backToMenu);
    connect(backToMenu,SIGNAL(clicked()),this,SLOT(backButton()));
}
void Menu::optionButton()
{
    removeButtons();

    gameModeModeTitle->setPlainText("Options");
    gameModeModeTitle->setFont(QFont("times",90, QFont::Bold, true));
    gameModeModeTitle->setPos(game->scene->width()/2-220,95);
    game->scene->addItem(gameModeModeTitle);

    highScoreDisplay->setPlainText("Background Volume\n\nExplosion Volume\n\nShoot Volume");
    highScoreDisplay->setPos(game->scene->width()/2-400, 400);
    game->scene->addItem(highScoreDisplay);

    volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
    volumeDisplay->setPos(game->scene->width()/2+210, 400);
    game->scene->addItem(volumeDisplay);

    game->scene->addItem(backgroundVolumIncreasee);
    connect(backgroundVolumIncreasee,SIGNAL(clicked()),this,SLOT(backgroundVolumIncreaseeButton()));

    game->scene->addItem(backgroundVolumDecrease);
    connect(backgroundVolumDecrease,SIGNAL(clicked()),this,SLOT(backgroundVolumDecreaseButton()));

    game->scene->addItem(explosiondVolumIncreasee);
    connect(explosiondVolumIncreasee,SIGNAL(clicked()),this,SLOT(explosiondVolumIncreaseeButton()));

    game->scene->addItem(explosionVolumDecrease);
    connect(explosionVolumDecrease,SIGNAL(clicked()),this,SLOT(explosionVolumDecreaseButton()));

    game->scene->addItem(shootdVolumIncreasee);
    connect(shootdVolumIncreasee,SIGNAL(clicked()),this,SLOT(shootdVolumIncreaseeButton()));

    game->scene->addItem(shotdVolumDecrease);
    connect(shotdVolumDecrease,SIGNAL(clicked()),this,SLOT(shotdVolumDecreaseButton()));

    game->scene->addItem(backToMenu);
    connect(backToMenu,SIGNAL(clicked()),this,SLOT(backButton()));
}
void Menu::backgroundVolumIncreaseeButton()
{
    if(game->backgroundVolume<=95)
    {
        game->backgroundVolume+=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
        game->backgroundMusic->setVolume(game->backgroundVolume);
    }
}
void Menu::backgroundVolumDecreaseButton()
{
    if(game->backgroundVolume>=5)
    {
        game->backgroundVolume-=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
        game->backgroundMusic->setVolume(game->backgroundVolume);
    }
}
void Menu::explosiondVolumIncreaseeButton()
{
    if(game->explosionVolume<=95)
    {
        game->explosionVolume+=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
    }
}
void Menu::explosionVolumDecreaseButton()
{
    if(game->explosionVolume>=5)
    {
        game->explosionVolume-=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
    }
}
void Menu::shootdVolumIncreaseeButton()
{
    if(game->shootVolume<=95)
    {
        game->shootVolume+=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
    }
}
void Menu::shotdVolumDecreaseButton()
{
    if(game->shootVolume>=5)
    {
        game->shootVolume-=5;
        volumeDisplay->setPlainText(QString::number(game->backgroundVolume)+"\n\n"+QString::number(game->explosionVolume)+"\n\n"+QString::number(game->shootVolume));
    }
}
void Menu::startGameButton()
{
    game->startGame();
    delete this;
}

void Menu::startGameTwoPlayersButton()
{
    game->startGameTwoPlayers();
    delete this;
}
void Menu::levelOneButton()
{
    game->startGame();
    game->lvlChosen=1;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelTwoButton()
{
    game->startGame();
    game->lvlChosen=2;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelThreeButton()
{
    game->startGame();
    game->lvlChosen=3;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelFourButton()
{
    game->startGame();
    game->lvlChosen=4;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelFiveButton()
{
    game->startGame();
    game->lvlChosen=5;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelSixButton()
{
    game->startGame();
    game->lvlChosen=6;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelSevenButton()
{
    game->startGame();
    game->lvlChosen=7;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelEightButton()
{
    game->startGame();
    game->lvlChosen=8;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelNineButton()
{
    game->startGame();
    game->lvlChosen=9;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelTenButton()
{
    game->startGame();
    game->lvlChosen=10;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::levelEndlessModeButton()
{
    game->startGame();
    game->lvlChosen=11;
    game->lvl->setLvl(game->lvlChosen);
    delete this;
}
void Menu::loadGameButton()
{
    game->startGame();

    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/ClassicModeSave.db");

    if(!dataBase.open())
        qDebug() << "Database open error";

    QSqlQuery level("SELECT Level FROM Saves WHERE SaveID=1;");
    int idLevel = level.record().indexOf("Level");
    level.next();
    game->lvl->setLvl(level.value(idLevel).toInt());
    QSqlQuery score("SELECT Score FROM Saves WHERE SaveID=1;");
    int idScore = score.record().indexOf("Score");
    score.next();
    game->score->setScore(score.value(idScore).toInt());

    delete this;
}
void Menu::backButton()
{
    removeButtons();
    createMenu();
}

void Menu::highScoresFromDatabase()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");

    if(highScoreType=="classicMode")
        dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/classicModeScores.db");
    else if(highScoreType=="arcadeMode")
        dataBase.setDatabaseName("D:/qt/Programy/Game_test_v3/arcadeModeScores .db");

    if(!dataBase.open())
        qDebug() << "Database open error";

    QSqlQuery query("SELECT PlayerScore FROM Scores ORDER BY PlayerScore DESC");
    int idScore = query.record().indexOf("PlayerScore");


    for(int i=0;i<10;i++)
    {
        query.next();
        highScoresTable[i] = query.value(idScore).toString();
        qDebug() << highScoresTable[i];
    }

    dataBase.close();
}

void Menu::highScoreChangeButton()
{
    if(highScoreType=="classicMode")
    {
        highScoreType="arcadeMode";
        highScoreChange->text->setPlainText("Arcade Mode");
        gameModeModeTitle->setPlainText("High Scores Arcade");
    }
    else if(highScoreType=="arcadeMode")
    {
        highScoreType="classicMode";
        highScoreChange->text->setPlainText("Classic Mode");
        gameModeModeTitle->setPlainText("High Scores Classic");
    }

    highScoresFromDatabase();

    scoresTable="Rank\t\t\tScore\n\n";

    for(int i=0;i<10;i++)
    {
        if(i==0)
             scoresTable+=QString::number(i+1)+"st\t\t\t\t"+highScoresTable[i]+"\n";
        else if(i==1)
            scoresTable+=QString::number(i+1)+"nd\t\t\t\t"+highScoresTable[i]+"\n";
        else if(i==2)
            scoresTable+=QString::number(i+1)+"rd\t\t\t\t"+highScoresTable[i]+"\n";
        else if(3<=i && i<=8)
            scoresTable+=QString::number(i+1)+"th\t\t\t\t"+highScoresTable[i]+"\n";
        else
            scoresTable+=QString::number(i+1)+"th\t\t\t\t"+highScoresTable[i]+"\n";
    }

    highScoreDisplay->setPlainText(scoresTable);
}

