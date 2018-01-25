#include "itembaseclass.h"

ItemBaseClass::ItemBaseClass(PenWidget *PW, BrushWidget *BW, RoundCornersWidget *RW)
    : QObject(), QGraphicsItem()
{
    PWID = PW;
    BWID = BW;
    RWID = RW;
    SetParameters();
    //connect(PW, SIGNAL(Changed()), this, SLOT(SetCommonParameters()));
}

void ItemBaseClass::SetYX(qreal xx, qreal yy)
{
    x = xx;
    y = yy;
}

void ItemBaseClass::SetParameters()
{
    pen = PWID->ReturnPen();
    PenWIDTH = PWID->PenWIDTH;
    OPACITY = PWID->OPACITY;
    ANGLE = PWID->ANGLE;

    brush = BWID->ReturnBrush();

    RoundX = RWID->ROUNDCornersX;
    RoundY = RWID->ROUNDCornersY;
}

ItemBaseClass::~ItemBaseClass()
{

}
