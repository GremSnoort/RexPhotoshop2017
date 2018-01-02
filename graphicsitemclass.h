#ifndef GRAPHICSITEMCLASS_H
#define GRAPHICSITEMCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "commonwidget.h"

class GraphicsItemClass
{

public:
    GraphicsItemClass();

    static QGraphicsItem* CreateNewRect(QGraphicsRectItem*IT, CommonWidget*WID);
    static QGraphicsItem* CreateNewEll(QGraphicsEllipseItem*IT, CommonWidget*WID);






signals:

public slots:
};

#endif // GRAPHICSITEMCLASS_H
