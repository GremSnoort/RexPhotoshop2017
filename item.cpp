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
    ANGLE = WID->ANGLE;
}

void Item::SetYX(qreal xx, qreal yy)
{
    xx = yy*sin(ANGLE*M_PI/180) + xx*cos(ANGLE*M_PI/180);
    yy = yy*cos(ANGLE*M_PI/180) - xx*sin(ANGLE*M_PI/180);
    x = xx;
    y = yy;
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

     /*   if(WID->PenWIDTH>0)painter->setPen(WID->ReturnPen());
        else painter->setPen(Qt::NoPen);
        painter->setBrush(WID->ReturnBrush());
        painter->setOpacity(WID->OPACITY);
        painter->rotate(WID->ANGLE);

        if(T==3)painter->drawRoundRect(x, y, a, b, WID->ROUNDCornersX, WID->ROUNDCornersY);
        else if(T==1)painter->drawRect(x, y, dx, dy);
        else if(T==2)painter->drawEllipse(x, y, dx, dy);*/


    if(PenWIDTH>0)painter->setPen(pen);
    else painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->setOpacity(OPACITY);
    painter->rotate(ANGLE);

    if(T==3)painter->drawRoundRect(x, y, a, b, RoundX, RoundY);
    else if(T==1)painter->drawRect(x, y, dx, dy);
    else if(T==2)painter->drawEllipse(x, y, dx, dy);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Item::boundingRect() const
{
    if(T==3)return QRectF(x, y, a, b);
    else return QRectF(x, y, dx, dy);
}
