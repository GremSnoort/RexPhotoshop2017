#include <algorithm>
#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    scene = new QGraphicsScene();



}



void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    previousPoint = event->scenePos();
    emit Press(event->scenePos().x(), event->scenePos().y());



    //itemsRECT->Items.push_back(dynamic_cast<QGraphicsRectItem*>(this->items().first()));

}





void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit Move(event->scenePos().x(), event->scenePos().y(), previousPoint.x(), previousPoint.y());


    //dynamic_cast<QGraphicsRectItem*>(this->items().first())->setRect(std::min(oldX, newX), std::min(oldY, newY), abs(oldX-newX), abs(oldY-newY));


}
void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit Release();


}



SceneClass::~SceneClass()
{

}
