#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    scene = new QGraphicsScene();

}

void SceneClass::MakeNew(int X, int Y)
{



}

void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->scenePos().x()<CurrentPixmap.width() && event->scenePos().y()<CurrentPixmap.height() && event->scenePos().x()>0 && event->scenePos().y()>0){

        this->addRect(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(Qt::red));


    /*this->addEllipse(event->scenePos().x() - 1,
               event->scenePos().y() - 1,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));*/

    previousPoint = event->scenePos();
    }
}

void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()<CurrentPixmap.width() && event->scenePos().y()<CurrentPixmap.height() && event->scenePos().x()>0 && event->scenePos().y()>0){


        this->addRect(QRectF(previousPoint, QSize(event->scenePos().x()-previousPoint.x(), event->scenePos().y()-previousPoint.y())), QPen(Qt::NoPen), QBrush(Qt::red));

       // this->removeItem(this->items().at(this->items().size()));
        //this->addRect( event->scenePos().x(), event->scenePos().y(), previousPoint.rx(), previousPoint.ry(),QPen(Qt::NoPen), QBrush(Qt::red));

  /*  this->addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red,1,Qt::SolidLine,Qt::RoundCap));*/

    //previousPoint = event->scenePos();
    }
}



SceneClass::~SceneClass()
{

}
