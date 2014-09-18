#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QtWidgets>



class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);
    void setSpot(QPushButton*, int, int);
    void computerTurn();
    void checkWinner(int);
    void won(int);
    int randInt(int, int);
    bool checkArrEqual(int[],int);
    void setStatusLabel(QLabel*);
    void noWinner();
    bool fillSpot(int);
    bool playing = true;


    QLabel *status;
    ~Board();

signals:
    void statusChanged(QString);


public slots:

};

#endif // BOARD_H
