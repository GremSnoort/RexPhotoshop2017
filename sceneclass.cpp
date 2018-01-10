#include <algorithm>
#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0, 0, WIDTH, HEIGHT);
}

void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    previousPoint = event->scenePos();

    update = true;
    UpdateSceneRect(event);
    emit Press(previousPoint.x(), previousPoint.y());    
}

void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit Move(event->scenePos().x(), event->scenePos().y(), previousPoint.x(), previousPoint.y());
}

void SceneClass::UpdateSceneRect(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()<X)
    {
        WIDTH+=abs(X-event->scenePos().x());
        X=event->scenePos().x();
    }
    if(event->scenePos().y()<Y)
    {
        HEIGHT+=abs(Y-event->scenePos().y());
        Y=event->scenePos().y();
    }
    if(abs(X-event->scenePos().x())>WIDTH)WIDTH = abs(X-event->scenePos().x());
    if(abs(Y-event->scenePos().y())>HEIGHT)HEIGHT = abs(Y-event->scenePos().y());
}

void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(update)
    {
        UpdateSceneRect(event);
        this->setSceneRect(X, Y, WIDTH, HEIGHT);
    }
    update = false;
    emit Release(event->scenePos().x(), event->scenePos().y());
}

SceneClass::~SceneClass()
{

}
