#include "itembaseclass.h"

ItemBaseClass::ItemBaseClass(PenWidget *PW)
    : QObject(), QGraphicsItem()
{
    PWID = PW;
    SetCommonParameters();
    connect(PW, SIGNAL(Changed()), this, SLOT(SetCommonParameters()));
}

void ItemBaseClass::SetCommonParameters()
{
    pen = PWID->ReturnPen();
    PenWIDTH = PWID->PenWIDTH;
    OPACITY = PWID->OPACITY;
    ANGLE = PWID->ANGLE;
}

ItemBaseClass::~ItemBaseClass()
{

}
