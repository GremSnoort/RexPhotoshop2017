#include "graphicsitemclass.h"

GraphicsItemClass::GraphicsItemClass()
{


}

QGraphicsItem* GraphicsItemClass::CreateNewRect(QGraphicsRectItem *IT, CommonWidget *WID)
{
    //pen.setStyle(Qt::DashLine);
    if(WID->PenWIDTH>0){
        QPen pen;
        pen.setWidth(WID->PenWIDTH);
        pen.setColor(WID->PenCOLOR);

        pen.setCapStyle(Qt::RoundCap);

        IT->setPen(pen);
    }else
        IT->setPen(Qt::NoPen);
    IT->setBrush(QBrush(WID->BrushCOLOR));
    IT->setOpacity(WID->OPACITY);

    return IT;

}
QGraphicsItem* GraphicsItemClass::CreateNewEll(QGraphicsEllipseItem *IT, CommonWidget *WID)
{
    if(WID->PenWIDTH>0){
        QPen pen;

        pen.setWidth(WID->PenWIDTH);
        pen.setColor(WID->PenCOLOR);

        pen.setCapStyle(Qt::RoundCap);

        IT->setPen(pen);
    }else
        IT->setPen(Qt::NoPen);
    IT->setBrush(QBrush(WID->BrushCOLOR));
    IT->setOpacity(WID->OPACITY);

    return IT;
}

