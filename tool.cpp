#include "tool.h"

Tool::Tool(QMainWindow *parent) : QObject()
{
    PenWID = new PenWidget(parent, 75);
    BrWID = new BrushWidget(parent, 655);
    RcWID = new RoundCornersWidget(parent, 525);

    PenWID->PenWIDGET->hide();
    BrWID->BrushWIDGET->hide();
    RcWID->RoundWIDGET->hide();

    B = new QPushButton(parent);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}
