#ifndef ROUNDRECTTOOL_H
#define ROUNDRECTTOOL_H

#include "itemroundrect.h"
#include "tool.h"
#include "toolregistrator.h"

class RoundRectToolRegistrator: public ToolRegistrator
{

public:
    explicit RoundRectToolRegistrator(){}
    Tool* makeTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);
};

class RoundRectTool : public Tool
{
    Q_OBJECT

public:
    explicit RoundRectTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);

    static RoundRectToolRegistrator RRTReg;

    SceneClass *sc;
    ItemRoundRect *it;

signals:

public slots:

    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();
    void ON();
    void OFF();

};

#endif // ROUNDRECTTOOL_H
