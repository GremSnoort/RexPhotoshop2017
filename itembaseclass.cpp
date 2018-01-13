#include "itembaseclass.h"

ItemBaseClass::ItemBaseClass(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

void ItemBaseClass::SetCommonParameters(PenWidget *PWID)
{
    pen = PWID->ReturnPen();
    PenWIDTH = PWID->PenWIDTH;
    OPACITY = PWID->OPACITY;
    ANGLE = PWID->ANGLE;
}

ItemBaseClass::~ItemBaseClass()
{

}
