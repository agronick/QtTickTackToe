#include "window.h"
#include "ui_window.h"
#include "board.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    init();

    connect(ui->resetBtn, SIGNAL(released()), this, SLOT(reset()));
}

void Window::reset()
{
    delete b;
    b = new Board();
    init();
}

void Window::init()
{

    connect(b, SIGNAL(statusChanged(QString)), this, SLOT(statusBar(QString)),Qt::DirectConnection);

    b->setSpot(ui->pos00, 0, 0);
    b->setSpot(ui->pos01, 0, 1);
    b->setSpot(ui->pos02, 0, 2);
    b->setSpot(ui->pos10, 1, 0);
    b->setSpot(ui->pos11, 1, 1);
    b->setSpot(ui->pos12, 1, 2);
    b->setSpot(ui->pos20, 2, 0);
    b->setSpot(ui->pos21, 2, 1);
    b->setSpot(ui->pos22, 2, 2);
    b->setStatusLabel(ui->status);

}

void Window::statusBar(QString update)
{
    ui->status->setText(update);
}



Window::~Window()
{
    delete ui;
}
