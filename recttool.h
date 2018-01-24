#ifndef RECTTOOL_H
#define RECTTOOL_H



#include "itemrect.h"
#include "toolregistrator.h"
#include "tool.h"
class RectToolRegistrator: public ToolRegistrator
{

public:
    explicit RectToolRegistrator(){}
    Tool* makeTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);
};

class RectTool : public Tool
{
    Q_OBJECT


public:
    explicit RectTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);

    static RectToolRegistrator RTReg;

    QPushButton *B;

    SceneClass *sc;

    ItemRect *it;

signals:


public slots:

    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();   

};

//


#endif // RECTTOOL_H
