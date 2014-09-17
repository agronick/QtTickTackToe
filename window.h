#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "board.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    Board *b = new Board();
    ~Window();


private:
    Ui::Window *ui;
    void init();

signals:


private slots:
    void reset();
    void statusBar(QString);

};

#endif // WINDOW_H
