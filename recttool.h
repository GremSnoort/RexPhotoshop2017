#ifndef RECTTOOL_H
#define RECTTOOL_H

#include "itemrect.h"
#include "tool.h"
#include "toolregistrator.h"

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

    SceneClass *sc;
    ItemRect *it;

signals:

public slots:

    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();
    void ON();
    void OFF();

};

#endif // RECTTOOL_H
