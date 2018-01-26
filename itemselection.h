#ifndef ITEMSELECTION_H
#define ITEMSELECTION_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

class ItemSelection : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemSelection();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

signals:

public slots:
};

#endif // ITEMSELECTION_H
