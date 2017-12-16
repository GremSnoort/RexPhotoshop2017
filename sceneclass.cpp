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

        if(QApplication::keyboardModifiers()==Qt::ShiftModifier)shiftmoveadd(prX, prY);



        else if(QApplication::keyboardModifiers()==Qt::ControlModifier)
        {
            controlresize(prX, prY);
            /*for(int i=0; i<(this->selectedItems().size()); i++)
            {
                qreal xc = this->selectedItems().at(i)->sceneBoundingRect().center().x();
                qreal yc = this->selectedItems().at(i)->sceneBoundingRect().center().y();
                qreal h2 = this->selectedItems().at(i)->sceneBoundingRect().height()/2;
                qreal w2 = this->selectedItems().at(i)->sceneBoundingRect().width()/2;

                qreal dx = prX-xc;
                qreal dy = prY-yc;

                qreal M = dx/w2;
                if(M<(dy/h2))M = dy/h2;
                QPointF F = this->selectedItems().at(i)->sceneBoundingRect().center();

                QTransform t;

                t.translate(F.x(), F.y());
                //t.rotate(30);
                t.scale(M, M);
                t.translate(-F.x(), -F.y());


                qreal tmpX=M*w2;
                qreal tmpY=M*h2;


                if(this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()>0 && this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()>0 && this->selectedItems().at(i)->sceneBoundingRect().topRight().x()<CurrentPixmap.width() && this->selectedItems().at(i)->sceneBoundingRect().topRight().y()>0 && this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().x()>0 && this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().y()<CurrentPixmap.height() && this->selectedItems().at(i)->sceneBoundingRect().bottomRight().x()<CurrentPixmap.width() && this->selectedItems().at(i)->sceneBoundingRect().bottomRight().y()<CurrentPixmap.height())
                {
                this->selectedItems().at(i)->setTransform(t);

                this->selectedItems().at(i)->setSelected(true);
                }

            }*/
        }


        ///____________
      // if(QApplication::keyboardModifiers()==Qt::KeyboardModifier())fill();










        if(RectMODE)
        {
            this->addRect(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstRect = true;
        }
        else if(CircleMODE)
        {
            this->addEllipse(QRectF(event->scenePos(), QSize(1, 1)), QPen(Qt::NoPen), QBrush(COLOR));
            FirstEllipse = true;
        }










       else if(QApplication::keyboardModifiers()==Qt::MetaModifier)
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

        t.scale(M, M);
        t.translate(-F.x(), -F.y());

        qreal tx = (this->selectedItems().at(i)->sceneBoundingRect().width()*M/2)-this->selectedItems().at(i)->sceneBoundingRect().width();
        qreal ty = (this->selectedItems().at(i)->sceneBoundingRect().height()*M/2)-this->selectedItems().at(i)->sceneBoundingRect().height();

        if(M<1 || this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()-tx>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()-ty>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().topRight().x()+tx<CurrentPixmap.width() &&
                this->selectedItems().at(i)->sceneBoundingRect().topRight().y()-ty>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().x()-tx>0 &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().y()+ty<CurrentPixmap.height() &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomRight().x()-tx<CurrentPixmap.width() &&
                this->selectedItems().at(i)->sceneBoundingRect().bottomRight().y()+ty<CurrentPixmap.height())
        {
            this->selectedItems().at(i)->setTransform(t);
        }

/*
        //QGraphicsItem *it = this->selectedItems().at(i);
//it->setTransform(t);
QTextStream out(stdout);

qreal scCX = this->selectedItems().at(i)->sceneBoundingRect().center().x();
qreal scCY = this->selectedItems().at(i)->sceneBoundingRect().center().y();
qreal scW = this->selectedItems().at(i)->sceneBoundingRect().width();
qreal scH = this->selectedItems().at(i)->sceneBoundingRect().height();

bool tX = scCX-(scW*M/2)>0 && scCX+(scW*M/2)<CurrentPixmap.width();
bool tY = scCY-(scH*M/2)>0 && scCY+(scH*M/2)<CurrentPixmap.height();



        if(tX && tY || M<1){
            out<<"!!!"<<this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()<<endl;

            this->selectedItems().at(i)->setTransform(t);
            out<<M<<"  "<<this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()<<endl;
        }





*/
        /*if(this->selectedItems().at(i)->sceneBoundingRect().topLeft().x()<0 && this->selectedItems().at(i)->sceneBoundingRect().topLeft().y()<0 && this->selectedItems().at(i)->sceneBoundingRect().topRight().x()>CurrentPixmap.width() && this->selectedItems().at(i)->sceneBoundingRect().topRight().y()<0 && this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().x()<0 && this->selectedItems().at(i)->sceneBoundingRect().bottomLeft().y()>CurrentPixmap.height() && this->selectedItems().at(i)->sceneBoundingRect().bottomRight().x()>CurrentPixmap.width() && this->selectedItems().at(i)->sceneBoundingRect().bottomRight().y()>CurrentPixmap.height())
        {
            //out<<dx/w2<<" "<<dy/h2<<"     "<<xc<<"  "<<yc<<"____________"<<xc-tmpX<<"  "<<xc+tmpX<<"  "<<yc-tmpY<<"  "<<yc+tmpY<<endl;

            t.translate(F.x(), F.y());

            t.scale(1/M, 1/M);
            t.translate(-F.x(), -F.y());


            this->selectedItems().at(i)->setTransform(t);

            //this->selectedItems().at(i)->update(xc-tmpX, yc-tmpY, tmpX*2, tmpY*2);
        }*/






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

    if(QApplication::keyboardModifiers()==Qt::ControlModifier)
    {
        controlresize(newX, newY);
    }


    if(QApplication::keyboardModifiers()==Qt::ShiftModifier)shiftmoveadd(newX, newY);


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
    if(QApplication::keyboardModifiers()==Qt::ShiftModifier)
    {
        //this->clearSelection();
    }


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
