#include "tool.h"

Tool::Tool(QMainWindow *parent) : QObject()
{
    PenWID = new PenWidget(parent, 0);
    BrWID = new BrushWidget(parent, 585);
    RcWID = new RoundCornersWidget(parent, 320);
}




