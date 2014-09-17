#ifndef SPACE_H
#define SPACE_H

#include <QObject>
#include <QtWidgets>
#include "board.h"

class Space : public QObject
{
    Q_OBJECT
public:
    explicit Space(QObject *parent = 0);
    void setLabel(QPushButton*);
    bool computerTurn();
    enum Status {N = 0, X = 1, O = 2};
    int getState();
    void setCoords(int, int);
    int* getCoords();
    Status state;
    Board *base;
    QPushButton *label;
    int x;
    int y;


signals:

public slots:
    void onClick();
};

#endif // SPACE_H
