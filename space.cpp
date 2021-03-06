#include "space.h"
#include "board.h"

Space::Space(QObject *parent) :
    QObject(parent)
{
    state = N;
}

void Space::setParent(Board *board)
{
    this->base = board;
}

void Space::setLabel(QPushButton *label)
{
    this->label = label;
    this->label->setMinimumHeight(80);
    this->label->setMinimumWidth(80);
    connect(this->label, SIGNAL(clicked()), this, SLOT(onClick()));
}

void Space::onClick()
{
    if(!base->playing)
        return;

    if(state == N)
    {
        state = X;
        this->label->setText(" X ");
        base->checkWinner(1);

        if(!base->playing)
            return;

        base->computerTurn();
        base->checkWinner(2);
    }
}

bool Space::computerTurn()
{
    if(state == N)
    {
        state = O;
        this->label->setText(" O ");
        return true;
    }
    return false;
}

int Space::getState()
{
    return this->state;
}

void Space::setCoords(int ax, int ay)
{
    x = ax;
    y = ay;
}

int* Space::getCoords()
{
    int arr[] = {x,y};
    return arr;
}
