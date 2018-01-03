#include "item.h"

Item::Item(QObject *parent, CommonWidget *W)
    : QObject(parent), QGraphicsItem()
{
    WID = W;
}
Item::~Item()
{

}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(WID->PenWIDTH>0)painter->setPen(WID->ReturnPen());
    else painter->setPen(Qt::NoPen);
    painter->setBrush(WID->ReturnBrush());
    painter->setOpacity(WID->OPACITY);

    painter->drawRoundRect(WID->PenWIDTH, WID->PenWIDTH,  a, b, 25, 25);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Item::boundingRect() const
{
    return QRectF(0,0,100,100);
}
