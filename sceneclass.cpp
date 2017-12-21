#include "sceneclass.h"

SceneClass::SceneClass(QObject *parent) : QGraphicsScene(parent)
{
    scene = new QGraphicsScene();

    CountOfItems=0;


}

QColor SceneClass::getColor(qreal newX, qreal newY)
{
    QPixmap paintDevice(this->width(), this->height());
    QPainter *painter = new QPainter(&paintDevice);
    this->render(painter);
    QImage pixels = paintDevice.toImage();
    QRgb colorAt = pixels.pixel(newX,newY);
    return QColor(colorAt);
}

void SceneClass::fill()
{
    for(int i=0; i<(this->items().size()-1); i++)
    {
        if(this->items().at(i)->isUnderMouse())
        {
            QGraphicsItem *I = this->items().at(i);

            if(getColor(this->items().at(i)->sceneBoundingRect().topLeft().x()+5, this->items().at(i)->sceneBoundingRect().topLeft().y()+5)==getColor(this->items().at(i)->sceneBoundingRect().center().x(), this->items().at(i)->sceneBoundingRect().center().y()))
            {
                this->removeItem(this->items().at(i));
                this->addRect(I->boundingRect(), QPen(Qt::NoPen), QBrush(COLOR));
            }

            else
            {
                this->removeItem(this->items().at(i));
                this->addEllipse(I->boundingRect(), QPen(Qt::NoPen), QBrush(COLOR));
            }


                /*
            QPainter *painter ;
            painter->setMatrix(this->items().at(i)->sceneMatrix(), true);
                      painter->setBrush(QBrush (COLOR));
                      this->setPalette(QPalette(COLOR));
             //this->items().at(i)->QAbstractGraphicsShapeItem::setBrush(QBrush(COLOR));
                             // paint(painter, new QStyleOptionGraphicsItem());*/

        }

    }

}

void SceneClass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->scenePos().x()<CurrentPixmap.width() && event->scenePos().y()<CurrentPixmap.height() && event->scenePos().x()>0 && event->scenePos().y()>0 && IsWorkSpace)
    {

        if(QApplication::keyboardModifiers()==Qt::KeyboardModifier())fill();

        previousPoint = event->scenePos();


        if(QApplication::keyboardModifiers()==Qt::ControlModifier)
        {
           for(int i=0; i<(this->items().size()-1); i++)
           {
               if(this->items().at(i)->isUnderMouse())
               {
                   F = this->items().at(i)->sceneBoundingRect();

                   qreal prX = F.topLeft().x();
                   qreal prY = F.topLeft().y();
                   qreal newX = event->scenePos().x();
                   qreal newY = event->scenePos().y();
                   if(prX>CurrentPixmap.width())prX = CurrentPixmap.width();
                   if(prY>CurrentPixmap.height())prY = CurrentPixmap.height();
                   if(prX<0)prX=0;
                   if(prY<0)prY=0;


                   Q = getColor(F.center().x(), F.center().y());

                   IsRect = getColor(this->items().at(i)->sceneBoundingRect().topLeft().x()+2, this->items().at(i)->sceneBoundingRect().topLeft().y()+2)==Q;


                   this->removeItem(this->items().at(i));
                   CountOfItems-=1;



                   if(IsRect)
                   rec(prX, prY, newX, newY, Q);
                   else ell(prX, prY, newX, newY, Q);



                   firstredraw=true;

                   break;
               }
           }
        }

        if(QApplication::keyboardModifiers()==Qt::ShiftModifier)
        {
            for(int i=0; i<(this->items().size()-1); i++)
            {
                if(this->items().at(i)->isUnderMouse())
                {
                    F = this->items().at(i)->sceneBoundingRect();
                    Q = getColor(F.center().x(), F.center().y());

                    IsRect = getColor(this->items().at(i)->sceneBoundingRect().topLeft().x()+2, this->items().at(i)->sceneBoundingRect().topLeft().y()+2)==Q;


                    this->removeItem(this->items().at(i));
                    CountOfItems-=1;

                    shiftmoveadd(event->scenePos().x(), event->scenePos().y());

                    firstmove=true;
                    break;
                }
            }
        }



       if(QApplication::keyboardModifiers()==Qt::MetaModifier)
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



       if(RectMODE && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ShiftModifier)
       {
           this->addRect(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
           FirstRect = true;
       }
       if(CircleMODE && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ShiftModifier)
       {
           this->addEllipse(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
           FirstEllipse = true;
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

void SceneClass::shiftmoveadd(qreal newX, qreal newY)
{
    qreal x1 = newX-(F.width()/2);
    qreal x2 = newX+(F.width()/2);
    qreal y1 = newY-(F.height()/2);
    qreal y2 = newY+(F.height()/2);

    if(x1>CurrentPixmap.width())x1 = CurrentPixmap.width();
    if(y1>CurrentPixmap.height())y1 = CurrentPixmap.height();
    if(x1<0)x1=0;
    if(y1<0)y1=0;

    if(x2>CurrentPixmap.width())x2 = CurrentPixmap.width();
    if(y2>CurrentPixmap.height())y2 = CurrentPixmap.height();
    if(x2<0)x2=0;
    if(y2<0)y2=0;


    if(IsRect) rec(x1, y1, x2, y2, Q);
    else ell(x1, y1, x2, y2, Q);


}


void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(IsWorkSpace)
    {
    qreal prX = previousPoint.x();
    qreal prY = previousPoint.y();

    qreal newX = event->scenePos().x();
    qreal newY = event->scenePos().y();

    if(newX>CurrentPixmap.width())newX = CurrentPixmap.width();
    if(newY>CurrentPixmap.height())newY = CurrentPixmap.height();
    if(newX<0)newX=0;
    if(newY<0)newY=0;

    if(RectMODE && FirstRect)rec(prX, prY, newX, newY, COLOR);
    if(CircleMODE && FirstEllipse)ell(prX, prY, newX, newY, COLOR);

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && firstredraw)
    {
        qreal prX = F.topLeft().x();
        qreal prY = F.topLeft().y();

        if(prX>CurrentPixmap.width())prX = CurrentPixmap.width();
        if(prY>CurrentPixmap.height())prY = CurrentPixmap.height();
        if(prX<0)prX=0;
        if(prY<0)prY=0;

        if(IsRect)rec(prX, prY, newX, newY, Q);
        else ell(prX, prY, newX, newY, Q);
    }


    if(QApplication::keyboardModifiers()==Qt::ShiftModifier && firstmove)shiftmoveadd(newX, newY);


    }
}
void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(RectMODE && IsWorkSpace)
    {
    FirstRect=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsMovable);

    }
    if(CircleMODE && IsWorkSpace)
    {
    FirstEllipse=false;
    CountOfItems+=1;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);

    }

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && IsWorkSpace)
    {
        firstredraw=false;
        CountOfItems+=1;
        IsModified=true;
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);
    }

    if(QApplication::keyboardModifiers()==Qt::ShiftModifier && IsWorkSpace)
    {
        CountOfItems+=1;
        IsModified=true;
        firstmove=false;
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);
    }
}



SceneClass::~SceneClass()
{

}
