#include "rect.h"

Rect::Rect(QRectF F, QPen P, QBrush B, qreal Opacity, qreal Angle) : QObject(), QGraphicsRectItem()
{
    RECTANGLE = new QGraphicsRectItem(F);
    RECTANGLE->setBrush(B);
    RECTANGLE->setPen(P);
    RECTANGLE->setOpacity(Opacity);
    RECTANGLE->setRotation(Angle);
}

void Rect::Update(qreal oldX, qreal oldY, qreal newX, qreal newY)
{
    this->setRect(std::min(oldX, newX), std::min(oldY, newY), abs(oldX-newX), abs(oldY-newY));
}
