#ifndef ITEMRECT_H
#define ITEMRECT_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

class ItemRect : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemRect();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

signals:

public slots:
};

#endif // ITEMRECT_H
