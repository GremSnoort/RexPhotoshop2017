#ifndef ELLTOOL_H
#define ELLTOOL_H

#include "itemell.h"
#include "tool.h"
#include "toolregistrator.h"

class EllToolRegistrator: public ToolRegistrator
{

public:
    explicit EllToolRegistrator(){}
    Tool* makeTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);
};

class EllTool : public Tool
{
    Q_OBJECT

public:
    explicit EllTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0);

    static EllToolRegistrator ETReg;

    SceneClass *sc;
    ItemEll *it;

signals:

public slots:

    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();
    void ON();
    void OFF();

};

#endif // ELLTOOL_H
