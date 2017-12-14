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

        }
        if(CircleMODE==true)
        {
            this->addEllipse(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstEllipse = true;
        }

        previousPoint = event->scenePos();

        if(RedrawMODE==true)
        {
           for(int i=0; i<(this->items().size()-1); i++)
           {
               if(this->items().at(i)->isUnderMouse())
               {

                   F = this->items().at(i)->boundingRect();

                   QPixmap paintDevice(this->width(), this->height());
                   QPainter *painter = new QPainter(&paintDevice);
                   this->render(painter);
                   QImage pixels = paintDevice.toImage();
                   QRgb colorAt = pixels.pixel(event->scenePos().x(),event->scenePos().y());
                   Q = QColor(colorAt);

                   this->removeItem(this->items().at(i));

                   qreal prX = F.topLeft().x();
                   qreal prY = F.topLeft().y();

                   qreal newX = event->scenePos().x();
                   qreal newY = event->scenePos().y();

                   if(prX>CurrentPixmap.width())prX = CurrentPixmap.width();
                   if(prY>CurrentPixmap.height())prY = CurrentPixmap.height();
                   if(prX<0)prX=0;
                   if(prY<0)prY=0;

                   //this->addRect(QRectF(F.topLeft(), QSize(event->scenePos().x()-F.topLeft().x(), event->scenePos().y()-F.topLeft().y())), QPen(Qt::NoPen), QBrush(Q));

                   rec(prX, prY, newX, newY, Q);


                   CountOfItems-=1;
                   break;
               }
           }
        }


       if(QApplication::keyboardModifiers() == Qt::ShiftModifier)
        {
           for(int i=0; i<(this->items().size()-1); i++)
           {

               if(this->items().at(i)->isUnderMouse())
               {
                   this->removeItem(this->items().at(i));
                   CountOfItems-=1;
                   IsModified=true;
                   break;
               }
           }
        }




    }

}


void SceneClass::rec(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q)
{
    if(this->items().size()>CountOfItems)this->removeItem(this->items().first());

    if(prX>newX && prY>newY)this->addRect(QRectF(QPointF(newX, newY), QSize(prX-newX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY>prY)this->addRect(QRectF(QPointF(prX, prY), QSize(newX-prX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY<prY)this->addRect(QRectF(QPointF(prX, newY), QSize(newX-prX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX<prX && newY>prY)this->addRect(QRectF(QPointF(newX, prY), QSize(prX-newX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));

}

void SceneClass::ell(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q)
{
    if(this->items().size()>CountOfItems)this->removeItem(this->items().first());

    if(prX>newX && prY>newY)this->addEllipse(QRectF(QPointF(newX, newY), QSize(prX-newX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY>prY)this->addEllipse(QRectF(QPointF(prX, prY), QSize(newX-prX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY<prY)this->addEllipse(QRectF(QPointF(prX, newY), QSize(newX-prX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX<prX && newY>prY)this->addEllipse(QRectF(QPointF(newX, prY), QSize(prX-newX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));
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
        if(FirstRect==true)rec(prX, prY, newX, newY, COLOR);
    }

    if(CircleMODE==true)
    {
        if(FirstEllipse==true)ell(prX, prY, newX, newY, COLOR);
    }


    if(RedrawMODE==true)
    {
        qreal prX = F.topLeft().x();
        qreal prY = F.topLeft().y();

        if(prX>CurrentPixmap.width())prX = CurrentPixmap.width();
        if(prY>CurrentPixmap.height())prY = CurrentPixmap.height();
        if(prX<0)prX=0;
        if(prY<0)prY=0;


        rec(prX, prY, newX, newY, Q);
    }



}

void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{


    if(RectMODE==true)
    {
    FirstRect=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsMovable);

    }
    if(CircleMODE==true)
    {
    FirstEllipse=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);

    }

    if(RedrawMODE==true)
    {
        CountOfItems+=1;
        IsModified=true;
    }

    //scene->setSelectionArea(QPainterPath(previousPoint), QTransform(1, 0, 0, 1, event->scenePos().x()-previousPoint.x(), event->scenePos().y()-previousPoint.y()));






}



SceneClass::~SceneClass()
{

}
