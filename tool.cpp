#include "tool.h"

Tool::Tool(QMainWindow *parent) : QObject()
{
    PenWID = new PenWidget(parent, 75);
    BrWID = new BrushWidget(parent, 655);
    RcWID = new RoundCornersWidget(parent, 525);


}




