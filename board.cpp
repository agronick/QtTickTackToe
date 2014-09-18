#include <QTime>
#include "board.h"
#include "space.h"
#include "window.h"
#include <QDebug>

int filled = 0;


Board::Board(QObject *parent) :
    QObject(parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    filled = 0;
}

Space *spaces[3][3];

void Board::setStatusLabel(QLabel *label)
{
    status = label;
    status->setText("");
}


void Board::setSpot(QPushButton *label, int x, int y)
{
    qDebug() << QString::number(x) << "-" << QString::number(y);
    spaces[x][y] = new Space();
    spaces[x][y]->setParent(this);
    spaces[x][y]->setLabel(label);
    spaces[x][y]->setCoords(x, y);
}

void Board::computerTurn()
{
    if(filled > 8)
    {
        noWinner();
        return;
    }

    if(!fillSpot(2))
    {
        if(!fillSpot(1))
        {
            bool spotNotFound = true;
            while(spotNotFound)
            {
                int x = randInt(0, 2);
                int y = randInt(0, 2);
                spotNotFound = !spaces[x][y]->computerTurn();
            }
        }
    }


}

bool Board::fillSpot(int look)
{

    int x_count = 0;
    int n_pos = -1;
    for(int i = 0; i < 3; i ++)
    {
        x_count = 0;
        n_pos = -1;
        for(int j = 0; j < 3; j++)
        {
            if(spaces[i][j]->getState() == look)
                x_count++;
            if(spaces[i][j]->getState() == 0)
                n_pos = j;
        }
        if(x_count == 2 && n_pos != -1)
        {
            spaces[i][n_pos]->computerTurn();
            return true;
        }

        x_count = 0;
        n_pos = -1;
        for(int k = 0; k < 3; k++)
        {
            if(spaces[k][i]->getState() == look)
                x_count++;
            if(spaces[k][i]->getState() == 0)
                n_pos = k;
        }
        if(x_count == 2 && n_pos != -1)
        {
            spaces[n_pos][i]->computerTurn();
            return true;
        }
    }

    Space **diag[] = {&spaces[0][0], &spaces[1][1], &spaces[2][2]};

    for(int j = 0; j < 2; j ++)
    {
        if(j == 1)
        {
            diag[0] = &spaces[0][2];
            diag[2] = &spaces[2][0];
        }

        n_pos = -1;
        x_count = 0;
        for(int i = 0; i < 3; i ++)
        {
             Space *item = *diag[i];
             if(item->getState() == look)
                 x_count++;
             if(item->getState() == 0)
                 n_pos = i;

             if(x_count == 2 && n_pos != -1)
             {
                 Space *set = *diag[n_pos];
                 set->computerTurn();
                 return true;
             }

        }
    }
    return false;
}

void Board::checkWinner(int check)
{
    filled++;

    int size = 3;
    for(int i = 0; i < 3; i++)
    {
       int nums[] = {spaces[i][0]->getState(), spaces[i][1]->getState(), spaces[i][2]->getState(), check};
       qDebug() << spaces[i][0]->getState() << spaces[i][1]->getState() << spaces[i][2]->getState() << check;
       if(checkArrEqual(nums, size))
            won(check);

       int nums2[] = {spaces[0][i]->getState(), spaces[1][i]->getState(), spaces[2][i]->getState(), check};
       if(checkArrEqual(nums2, size))
            won(check);
    }

    int nums3[4];
    nums3[0] = spaces[0][0]->getState();
    nums3[1] = spaces[1][1]->getState();
    nums3[2] = spaces[2][2]->getState();
    nums3[3] = check;
    if(checkArrEqual(nums3, size))
         won(check);

    nums3[0] = spaces[0][2]->getState();
    nums3[2] = spaces[2][0]->getState();
    if(checkArrEqual(nums3, size))
         won(check);
}

bool Board::checkArrEqual(int a[], int  n)
{
    for(int i = 0; i < (n); i++)
    {
        if(a[i] != a[i+1])
            return false;
    }
    return true;
}

void Board::won(int state)
{
    if(state == 1)
    {
        status->setText("You Win");
    }else if(state == 2)
    {
       status->setText("You Loose");
    }
    playing = false;
}

int Board::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void Board::noWinner()
{
    status->setText("Draw");
    playing = false;
}

Board::~Board()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            spaces[i][j]->label->setText("");
            delete spaces[i][j];
        }
    }
}


