#include "itemselection.h"

ItemSelection::ItemSelection(): ItemBaseClass()
{

}

void ItemSelection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setOpacity(1);
    painter->rotate(-ANGLE);
    painter->setPen(Qt::DashLine);
    painter->setBrush(QBrush(QColor(255, 255, 255, 0)));

    QPainterPath path;
    path.addRect(x, y, dx, dy);

    painter->drawPath(path);
    update(path.boundingRect());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF ItemSelection::boundingRect() const
{
    return QRectF(x, y, dx, dy);
}
