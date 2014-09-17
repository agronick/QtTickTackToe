#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QtWidgets>

class Item : public QObject
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = 0);
    QLabel *txt;

signals:

public slots:

};

#endif // SLOT_H
