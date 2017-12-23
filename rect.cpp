#include "rect.h"

Rect::Rect(QObject *parent) : QObject(), QGraphicsRectItem()
{
    Items = new QList<QGraphicsRectItem*>();


}

Rect::~Rect()
{

}

QGraphicsRectItem* Rect::CreateNew(QRectF F, QPen P, QBrush B, qreal Opacity, qreal Angle)
{
    RECTANGLE = new QGraphicsRectItem(F);
    RECTANGLE->setBrush(B);
    RECTANGLE->setPen(P);
    RECTANGLE->setOpacity(Opacity);
    RECTANGLE->setRotation(Angle);

    //Items->append(RECTANGLE);

    return RECTANGLE;
}


void Rect::Update( QRectF F)
{
    if(!Items->isEmpty())Items->last()->setRect(F);
                //std::min(oldX, newX), std::min(oldY, newY), abs(oldX-newX), abs(oldY-newY));
}
