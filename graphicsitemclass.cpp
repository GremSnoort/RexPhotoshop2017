#include "graphicsitemclass.h"

GraphicsItemClass::GraphicsItemClass()
{


}

QGraphicsItem* GraphicsItemClass::CreateNewRect(QGraphicsRectItem *IT, CommonWidget *WID)
{    
    if(WID->PenWIDTH>0){
        QPen pen;
        pen.setWidth(WID->PenWIDTH);
        pen.setColor(WID->PenCOLOR);
        pen.setStyle(WID->PenSTYLE);
        pen.setCapStyle(WID->CapSTYLE);
        pen.setJoinStyle(WID->JointSTYLE);

        pen.setCapStyle(Qt::RoundCap);

        IT->setPen(pen);
    }else
        IT->setPen(Qt::NoPen);
    QBrush br;
    br.setColor(WID->BrushCOLOR);
    br.setStyle(WID->BrushSTYLE);
    IT->setBrush(br);
    IT->setOpacity(WID->OPACITY);

    return IT;

}
QGraphicsItem* GraphicsItemClass::CreateNewEll(QGraphicsEllipseItem *IT, CommonWidget *WID)
{
    if(WID->PenWIDTH>0){
        QPen pen;

        pen.setWidth(WID->PenWIDTH);
        pen.setColor(WID->PenCOLOR);
        pen.setStyle(WID->PenSTYLE);
        pen.setCapStyle(WID->CapSTYLE);
        pen.setJoinStyle(WID->JointSTYLE);

        pen.setCapStyle(Qt::RoundCap);

        IT->setPen(pen);
    }else
        IT->setPen(Qt::NoPen);
    QBrush br;
    br.setColor(WID->BrushCOLOR);
    br.setStyle(WID->BrushSTYLE);
    IT->setBrush(br);
    IT->setOpacity(WID->OPACITY);

    return IT;
}

