#include "tool.h"

Tool::Tool(QMainWindow *parent) : QObject()
{
    B = new QPushButton(parent);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}
