#include "itembaseclass.h"

ItemBaseClass::ItemBaseClass(QObject *parent, PenWidget *PW)
    : QObject(parent), QGraphicsItem()
{
    PWID = PW;
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
