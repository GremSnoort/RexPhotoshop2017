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

            if(RectMODE)
            {
                this->removeItem(this->items().at(i));
                this->addRect(I->boundingRect(), QPen(Qt::NoPen), QBrush(COLOR));
            }

            if(CircleMODE)
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
        previousPoint = event->scenePos();
        qreal prX = previousPoint.x();
        qreal prY = previousPoint.y();

        for(int i=0; i<this->items().size()-1; i++)
        {
            this->items().at(i)->setFlag(QGraphicsItem::ItemIsSelectable, true);
            this->items().at(i)->setFlag(QGraphicsItem::ItemIsMovable, true);
            //this->items().at(i)->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
        }

        QPainterPath P(previousPoint);
        P.addRect(prX, prY, 1, 1);
        this->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());

        if(QApplication::keyboardModifiers()==Qt::ShiftModifier)
        {
            shiftmoveadd(prX, prY);
            firstmove=true;
        }


        else if(QApplication::keyboardModifiers()==Qt::ControlModifier)
        {
            controlresize(prX, prY);
            firstredraw=true;
        }

        else if(QApplication::keyboardModifiers()==Qt::MetaModifier)
         {
             for(int i=0; i<(this->selectedItems().size()); i++)
             {
                    this->removeItem(this->selectedItems().at(i));
                    CountOfItems-=1;
                    IsModified=true;
                    //break;
             }

         }


        ///____________
      // if(QApplication::keyboardModifiers()==Qt::KeyboardModifier())fill();










        if(RectMODE && !firstredraw && !firstmove)
        {
            this->addRect(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstRect = true;
        }
        else if(CircleMODE && !firstredraw && !firstmove)
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
    for(int i=0; i<(this->selectedItems().size()); i++)
    {
        qreal h2 = this->selectedItems().at(i)->boundingRect().height()/2;
        qreal w2 = this->selectedItems().at(i)->boundingRect().width()/2;

        if(newX<this->selectedItems().at(i)->sceneBoundingRect().width()/2)newX = this->selectedItems().at(i)->sceneBoundingRect().width()/2;
        if(newX>CurrentPixmap.width()-this->selectedItems().at(i)->sceneBoundingRect().width()/2)newX = CurrentPixmap.width()-this->selectedItems().at(i)->sceneBoundingRect().width()/2;

        if(newY<this->selectedItems().at(i)->sceneBoundingRect().height()/2)newY = this->selectedItems().at(i)->sceneBoundingRect().height()/2;
        if(newY>CurrentPixmap.height()-this->selectedItems().at(i)->sceneBoundingRect().height()/2)newY = CurrentPixmap.height()-this->selectedItems().at(i)->sceneBoundingRect().height()/2;

        qreal x = newX-this->selectedItems().at(i)->boundingRect().center().x();
        qreal y = newY-this->selectedItems().at(i)->boundingRect().center().y();

        this->selectedItems().at(i)->setPos(x, y);
        this->selectedItems().at(i)->update();


        QTextStream out(stdout);
        out<<this->selectedItems().at(i)->sceneBoundingRect().center().x()<<endl;

    }

}


void SceneClass::controlresize(qreal newX, qreal newY)
{
    for(int i=0; i<(this->selectedItems().size()); i++)
    {
        qreal xc = this->selectedItems().at(i)->boundingRect().center().x();
        qreal yc = this->selectedItems().at(i)->boundingRect().center().y();
        qreal h2 = this->selectedItems().at(i)->boundingRect().height()/2;
        qreal w2 = this->selectedItems().at(i)->boundingRect().width()/2;

        qreal dx = abs(newX-xc);
        qreal dy = abs(newY-yc);

        qreal M = dx/w2;
        if(M<(dy/h2))M = dy/h2;
        QPointF F = this->selectedItems().at(i)->boundingRect().center();        

        QTransform t;

        t.translate(F.x(), F.y());

        t.scale(dx/w2, dy/h2);
        t.translate(-F.x(), -F.y());

        qreal tx = (this->selectedItems().at(i)->sceneBoundingRect().width()*(dx/w2)/2)-this->selectedItems().at(i)->sceneBoundingRect().width();
        qreal ty = (this->selectedItems().at(i)->sceneBoundingRect().height()*(dy/h2)/2)-this->selectedItems().at(i)->sceneBoundingRect().height();

        if(M<1 || this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()-tx>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()-ty>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().topRight().x()+tx<CurrentPixmap.width() &&
                this->selectedItems().at(i)->sceneBoundingRect().topRight().y()-ty>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().x()-tx>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().y()+ty<CurrentPixmap.height() &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomRight().x()-tx<CurrentPixmap.width() &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomRight().y()+ty<CurrentPixmap.height())
        {
            QTextStream out(stdout);

            out<<"!!"<<this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()-ty<<"  "<<dx/w2<<"    "<<endl;
            this->selectedItems().at(i)->setTransform(t);
            //this->selectedItems().at(i)->update();
            out<<this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()<<"  "<<dx/w2<<"    "<<endl;
        }

    }
}

void SceneClass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->scenePos().x()<CurrentPixmap.width() && event->scenePos().y()<CurrentPixmap.height() && event->scenePos().x()>0 && event->scenePos().y()>0 && IsWorkSpace)
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

    /*QPainterPath P(previousPoint);
    P.addRect(prX, prY, newX-prX, newY-prY);
    this->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());*/

    if(RectMODE && FirstRect)rec(prX, prY, newX, newY, COLOR);
    else if(CircleMODE && FirstEllipse)ell(prX, prY, newX, newY, COLOR);

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && firstredraw)controlresize(newX, newY);

    if(QApplication::keyboardModifiers()==Qt::ShiftModifier && firstmove)shiftmoveadd(newX, newY);


    if(SelectMODE)
    {
        for(int i=0; i<this->items().size()-1; i++)
        {
            this->items().at(i)->setFlag(QGraphicsItem::ItemIsSelectable, true);
            this->items().at(i)->setFlag(QGraphicsItem::ItemIsMovable, true);
        }

        QTextStream out(stdout);
        out<<this->selectedItems().size()<<endl;
//this->items().at(2)->setPos(event->scenePos().x()-this->items().at(2)->boundingRect().center().x(), event->scenePos().y()-this->items().at(2)->boundingRect().center().y());
    }
}

    }
}
void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(RectMODE && IsWorkSpace)
    {
    FirstRect=false;
    CountOfItems+=1;
    IsModified=true;

    }
    if(CircleMODE && IsWorkSpace)
    {
    FirstEllipse=false;
    CountOfItems+=1;
    IsModified=true;


    }

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && IsWorkSpace)
    {
        firstredraw=false;
        CountOfItems+=1;
        IsModified=true;

    }

    if(QApplication::keyboardModifiers()==Qt::ShiftModifier && IsWorkSpace)
    {
        CountOfItems+=1;
        IsModified=true;
        firstmove=false;

    }
}



SceneClass::~SceneClass()
{

}
