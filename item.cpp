#include "item.h"

Item::Item(QObject *parent, CommonWidget *W)
    : QObject(parent), QGraphicsItem()
{
    WID = W;
}
Item::~Item()
{

}

void Item::SetParameters()
{
    OPACITY = WID->OPACITY;
    pen = WID->ReturnPen();
    brush = WID->ReturnBrush();
    PenWIDTH = WID->PenWIDTH;
    RoundX = WID->ROUNDCornersX;
    RoundY = WID->ROUNDCornersY;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    /*if(WID->PenWIDTH>0)painter->setPen(WID->ReturnPen());
    else painter->setPen(Qt::NoPen);
    painter->setBrush(WID->ReturnBrush());
    painter->setOpacity(WID->OPACITY);

    if(T==3)painter->drawRoundRect(WID->PenWIDTH, WID->PenWIDTH,  a, b, 25, 25);*/
    if(PenWIDTH>0)painter->setPen(pen);
    else painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->setOpacity(OPACITY);

    if(T==3)painter->drawRoundRect(PenWIDTH, PenWIDTH,  a, b, RoundX, RoundY);
    else if(T==1)painter->drawRect(x, y, dx, dy);
    else if(T==2)painter->drawEllipse(x, y, dx, dy);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Item::boundingRect() const
{
    return QRectF(0,0,100,100);
}
