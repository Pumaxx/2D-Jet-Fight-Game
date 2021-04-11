#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
    public:
        Score(QGraphicsItem * parent=0);
        void increase();
        int getScore();
        void setScore(int points);
        int score;
    private:

};

#endif // SCORE_H
