#ifndef SCENECLASS_H
#define SCENECLASS_H

#define private public


#include <QPixmap>
#include <QTransform>
#include <QAbstractGraphicsShapeItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QTextStream>
#include <QPixmap>

//#include "toolregistrator.h"
#include "tool.h"

class SceneClass : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SceneClass(QObject *parent = nullptr);
    ~SceneClass();

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);



    Tool *ActiveTOOL;


    QPointF     previousPoint;


    bool IsModified = false;


    qreal X = 0;
    qreal Y = 0;


    qreal HEIGHT = 895;

    qreal WIDTH = 1315;

    bool update = false;

    void UpdateSceneRect(QGraphicsSceneMouseEvent *event);


signals:
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);

    void Release(qreal newX, qreal newY);

public slots:
    //void ChangeTool()

};

#endif // SCENECLASS_H
