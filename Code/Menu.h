#ifndef MENU_H
#define MENU_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QtSql>
#include "Button.h"

class Menu: public QGraphicsTextItem
{
    Q_OBJECT

    public:
        Menu(QGraphicsItem * parent=0);
        ~Menu();
        QGraphicsRectItem* panelOne;
        QGraphicsRectItem* panelTwo;
        QGraphicsTextItem* menuTitle;
        QGraphicsTextItem* gameModeModeTitle;
        QGraphicsTextItem* highScoreDisplay;
        QGraphicsTextItem* volumeDisplay;
        Button* classicMode;
        Button* arcadeMode;
        Button* twoPlayersMode;
        Button* highScores;
        Button* options;
        Button* closeGame;
        Button* startGame; 
        Button* loadGame;
        Button* backToMenu;
        Button* highScoreChange;
        Button* levelOne;
        Button* levelTwo;
        Button* levelThree;
        Button* levelFour;
        Button* levelFive;
        Button* levelSix;
        Button* levelSeven;
        Button* levelEight;
        Button* levelNine;
        Button* levelTen;
        Button* levelEndlessMode;
        Button* backgroundVolumIncreasee;
        Button* backgroundVolumDecrease;
        Button* explosiondVolumIncreasee;
        Button* explosionVolumDecrease;
        Button* shootdVolumIncreasee;
        Button* shotdVolumDecrease;
        QSqlDatabase dataBase;
        QString scoresTable;
        QString highScoresTable[10];
        QString highScoreType;
        void highScoresFromDatabase();
        void createMenu();
        void removeButtons();
    public slots:
        void classicModeButton();
        void arcadeModeButton();
        void backgroundVolumIncreaseeButton();
        void backgroundVolumDecreaseButton();
        void explosiondVolumIncreaseeButton();
        void explosionVolumDecreaseButton();
        void shootdVolumIncreaseeButton();
        void shotdVolumDecreaseButton() ;
        void startGameButton();
        void startGameTwoPlayersButton();
        void loadGameButton();
        void twoPlayersModeButton();
        void highScoresButton();
        void optionButton();
        void backButton();
        void levelOneButton();
        void levelTwoButton();
        void levelThreeButton();
        void levelFourButton();
        void levelFiveButton();
        void levelSixButton();
        void levelSevenButton();
        void levelEightButton();
        void levelNineButton();
        void levelTenButton();
        void levelEndlessModeButton();
        void highScoreChangeButton();
};

#endif // MENU_H
