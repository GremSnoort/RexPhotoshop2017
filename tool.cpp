#include "tool.h"

Tool::Tool(QMainWindow *parent, SceneClass *scene, int y) : QObject(parent)
{
    PenWID = new PenWidget(parent, 0);
    BrWID = new BrushWidget(parent, 585);
    RcWID = new RoundCornersWidget(parent, 320);
}




