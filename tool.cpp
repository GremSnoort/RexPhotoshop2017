#include "tool.h"

Tool::Tool(QMainWindow *parent) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    PenWID = new PenWidget(parent, 0);
    BrWID = new BrushWidget(parent, 585);
    RcWID = new RoundCornersWidget(parent, 320);
}




