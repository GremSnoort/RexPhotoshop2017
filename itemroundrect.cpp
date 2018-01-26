#include "itemroundrect.h"

ItemRoundRect::ItemRoundRect() : ItemBaseClass()
{

}

void ItemRoundRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(PenWIDTH>0)painter->setPen(pen);
    else painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->setOpacity(OPACITY);
    painter->rotate(ANGLE);

    painter->drawRoundRect(x, y, dx, dy, RoundX, RoundY);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF ItemRoundRect::boundingRect() const
{
    return QRectF(x, y, dx, dy);
}
