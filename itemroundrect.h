#ifndef ITEMROUNDRECT_H
#define ITEMROUNDRECT_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

class ItemRoundRect : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemRoundRect();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

signals:

public slots:
};

#endif // ITEMROUNDRECT_H
