#ifndef ITEMRECT_H
#define ITEMRECT_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

#include "brushwidget.h"

class ItemRect : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemRect(BrushWidget *BW = nullptr, PenWidget *PW = nullptr);

    BrushWidget *BWID;

    QBrush brush;

    qreal x;
    qreal y;
    qreal dx = 1;
    qreal dy = 1;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void SetParameters();
    void SetYX(qreal xx, qreal yy);

signals:

public slots:
};

#endif // ITEMRECT_H
