#include "itemrect.h"

ItemRect::ItemRect(PenWidget *PW, BrushWidget *BW, RoundCornersWidget *RW) : ItemBaseClass(PW, BW, RW)
{

}

void ItemRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(PenWIDTH>0)painter->setPen(pen);
    else painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->setOpacity(OPACITY);
    painter->rotate(ANGLE);

    painter->drawRect(x, y, dx, dy);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF ItemRect::boundingRect() const
{
    return QRectF(x, y, dx, dy);
}
