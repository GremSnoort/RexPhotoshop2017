#ifndef RECTTOOL_H
#define RECTTOOL_H

#include "tool.h"
#include "itemrect.h"

class RectTool : public Tool
{
    Q_OBJECT


public:
    explicit RectTool(SceneClass *scene = nullptr);

    SceneClass *sc;

    ItemRect *it;

signals:


public slots:

    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();   

};

#endif // RECTTOOL_H
