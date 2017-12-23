#include <algorithm>
#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    itemsRECT = new Rect();

    ItemsList = new QList<all_items*>();
    ItemsList = {};
}



void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    emit Press(event, this);
   /* previousPoint = event->scenePos();
    qreal prX = previousPoint.x();
    qreal prY = previousPoint.y();



    this->addItem( itemsRECT->CreateNew(QRectF(prX, prY, 10, 10), QPen(Qt::NoPen), QBrush(QColor(100, 100, 100)), 100, 0) );*/

    //itemsRECT->Items.push_back(dynamic_cast<QGraphicsRectItem*>(this->items().first()));

}





void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  /*  qreal newX = event->scenePos().x();
    qreal newY = event->scenePos().y();
    qreal oldX = previousPoint.x();
    qreal oldY = previousPoint.y();
    //itemsRECT->update(std::min(oldX, newX), std::min(oldY, newY), abs(oldX-newX), abs(oldY-newY));
    dynamic_cast<QGraphicsRectItem*>(this->items().first())->setRect(std::min(oldX, newX), std::min(oldY, newY), abs(oldX-newX), abs(oldY-newY));*/


}
void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{



}



SceneClass::~SceneClass()
{

}
