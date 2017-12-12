#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    scene = new QGraphicsScene();
    CountOfItems=0;
}



void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()<CurrentPixmap.width() && event->scenePos().y()<CurrentPixmap.height() && event->scenePos().x()>0 && event->scenePos().y()>0){

        if(RectMODE==true)
        {
            this->addRect(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstRect = true;

            //auto itemClick = dynamic_cast<QGraphicsRectItem*>(this->itemAt(event->pos()));
        }
        if(CircleMODE==true)
        {
            this->addEllipse(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstEllipse = true;
        }
        previousPoint = event->scenePos();
    }

    int i = this->items().size();
    QTextStream out(stdout);
    out<<i<<"  "<<CountOfItems<<endl;
}

void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    qreal prX = previousPoint.x();
    qreal prY = previousPoint.y();

    qreal newX = event->scenePos().x();
    qreal newY = event->scenePos().y();

    if(newX>CurrentPixmap.width())newX = CurrentPixmap.width();
    if(newY>CurrentPixmap.height())newY = CurrentPixmap.height();
    if(newX<0)newX=0;
    if(newY<0)newY=0;

    if(RectMODE==true)
    {

    if(FirstRect==true)
    {
        if(this->items().size()>CountOfItems)this->removeItem(this->items().first());

        if(prX>newX && prY>newY)this->addRect(QRectF(QPointF(newX, newY), QSize(prX-newX, prY-newY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX>prX && newY>prY)this->addRect(QRectF(QPointF(prX, prY), QSize(newX-prX, newY-prY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX>prX && newY<prY)this->addRect(QRectF(QPointF(prX, newY), QSize(newX-prX, prY-newY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX<prX && newY>prY)this->addRect(QRectF(QPointF(newX, prY), QSize(prX-newX, newY-prY)), QPen(Qt::NoPen), QBrush(COLOR));
    }
    }

    if(CircleMODE==true)
    {

    if(FirstEllipse==true)
    {
        if(this->items().size()>CountOfItems)this->removeItem(this->items().first());

        if(prX>newX && prY>newY)this->addEllipse(QRectF(QPointF(newX, newY), QSize(prX-newX, prY-newY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX>prX && newY>prY)this->addEllipse(QRectF(QPointF(prX, prY), QSize(newX-prX, newY-prY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX>prX && newY<prY)this->addEllipse(QRectF(QPointF(prX, newY), QSize(newX-prX, prY-newY)), QPen(Qt::NoPen), QBrush(COLOR));
        else if(newX<prX && newY>prY)this->addEllipse(QRectF(QPointF(newX, prY), QSize(prX-newX, newY-prY)), QPen(Qt::NoPen), QBrush(COLOR));
    }
    }


    int i = this->items().size();
    QTextStream out(stdout);
    out<<i<<"  "<<CountOfItems<<endl;
}

void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(RectMODE==true)
    {
    FirstRect=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsItem::ItemIsMovable);
    }
    if(CircleMODE==true)
    {
    FirstEllipse=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsItem::ItemIsMovable);
    }


    int i = this->items().size();
    QTextStream out(stdout);
    out<<i<<"  "<<CountOfItems<<endl;

}



SceneClass::~SceneClass()
{

}
