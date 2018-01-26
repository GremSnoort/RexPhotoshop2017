#include "itembaseclass.h"

PenWidget *ItemBaseClass::PWID = 0;
BrushWidget *ItemBaseClass::BWID = 0;
RoundCornersWidget *ItemBaseClass::RWID = 0;

ItemBaseClass::ItemBaseClass()
    : QObject(), QGraphicsItem()
{
    SetParameters();
}

void ItemBaseClass::SetYX(qreal xx, qreal yy)
{
    x = xx;
    y = yy;
}

void ItemBaseClass::SetParameters()
{
    pen = ItemBaseClass::PWID->ReturnPen();
    PenWIDTH = ItemBaseClass::PWID->PenWIDTH;
    OPACITY = ItemBaseClass::PWID->OPACITY;
    ANGLE = ItemBaseClass::PWID->ANGLE;

    brush = ItemBaseClass::BWID->ReturnBrush();

    RoundX = ItemBaseClass::RWID->ROUNDCornersX;
    RoundY = ItemBaseClass::RWID->ROUNDCornersY;
}

ItemBaseClass::~ItemBaseClass()
{

}
