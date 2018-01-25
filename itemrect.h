#ifndef ITEMRECT_H
#define ITEMRECT_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

class ItemRect : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemRect(PenWidget *PW = 0, BrushWidget *BW = 0, RoundCornersWidget *RW = 0);

    qreal dx = 1;
    qreal dy = 1;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

signals:

public slots:
};

#endif // ITEMRECT_H
