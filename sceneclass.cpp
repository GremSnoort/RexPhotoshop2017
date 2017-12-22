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

bool SceneClass::TypeIsRect(QGraphicsItem *I)
{
    qreal x = I->sceneBoundingRect().topLeft().x();
    qreal y = I->sceneBoundingRect().topLeft().y();
    qreal xc = I->sceneBoundingRect().center().x();
    qreal yc = I->sceneBoundingRect().center().y();

    foreach (QGraphicsItem *it, this->items())
    {
        if(it!=I && it!=this->items().last())it->hide();
    }

    bool ans = getColor(x+5, y+5)==getColor(xc, yc);
    Q = getColor(xc, yc);

    foreach (QGraphicsItem *it, this->items())
    {
        if(it!=I && it!=this->items().last())it->show();
    }

    return ans;
}

void SceneClass::fill()
{
    foreach(QGraphicsItem *I, this->selectedItems())
    {
            QTextStream out(stdout);

            if(TypeIsRect(I))
            {
                this->removeItem(I);

                this->addRect(I->sceneBoundingRect(), QPen(Qt::NoPen), QBrush(COLOR));
                this->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable);
                this->items().first()->setFlag(QGraphicsRectItem::ItemIsMovable);
            }

            else
            {
                this->removeItem(I);

                this->addEllipse(I->sceneBoundingRect(), QPen(Qt::NoPen), QBrush(COLOR));
                this->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable);
                this->items().first()->setFlag(QGraphicsRectItem::ItemIsMovable);
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



                QPainterPath P(previousPoint);
                P.addRect(prX, prY, 1, 1);
        this->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());
/*
        if(FillMODE && QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)fill();




        else

       else  i



       else if(QApplication::keyboardModifiers()==Qt::MetaModifier&& !firstredraw && !firstmove)
        {
           for(int i=0; i<(this->selectedItems().size()); i++)
          {
                   this->removeItem(this->selectedItems().at(i));

                   CountOfItems-=1;
                   IsModified=true;
                   break;

           }
        }

*/

                if(QApplication::keyboardModifiers()==Qt::ControlModifier)
                        {
                            for(int i=0; i<(this->selectedItems().size()); i++)
                           {

                                   F = this->selectedItems().at(i)->sceneBoundingRect();

                                   qreal prX = F.topLeft().x();
                                   qreal prY = F.topLeft().y();
                                   qreal newX = event->scenePos().x();
                                   qreal newY = event->scenePos().y();
                                   if(prX>CurrentPixmap.width())prX = CurrentPixmap.width();
                                   if(prY>CurrentPixmap.height())prY = CurrentPixmap.height();
                                   if(prX<0)prX=0;
                                   if(prY<0)prY=0;


                                   IsRect = TypeIsRect(this->selectedItems().at(i));

                                   this->removeItem(this->selectedItems().at(i));
                                   --CountOfItems;

                                   if(IsRect)
                                   rec(prX, prY, newX, newY, Q);
                                   else ell(prX, prY, newX, newY, Q);


                                   firstredraw=true;

                                   break;

                           }
                        }

                else if(QApplication::keyboardModifiers()==Qt::ShiftModifier && !firstredraw)
                        {
                            for(int i=0; i<(this->selectedItems().size()); i++)
                           {

                                    F = this->selectedItems().at(i)->sceneBoundingRect();
                                    IsRect = TypeIsRect(this->selectedItems().at(i));


                                    this->removeItem(this->selectedItems().at(i));
                                    --CountOfItems;

                                    shiftmoveadd(event->scenePos().x(), event->scenePos().y());

                                    firstmove=true;
                                    break;

                            }
                        }

       else if(RectMODE && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)
       {
           this->addRect(QRectF(event->scenePos(), QSize(10, 10)), QPen(Qt::NoPen), QBrush(COLOR));

           FirstRect = true;
       }
       else if(CircleMODE && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)
       {
           this->addEllipse(QRectF(event->scenePos(), QSize(10, 10)), QPen(Qt::NoPen), QBrush(COLOR));

           FirstEllipse = true;
       }




    }

}


void SceneClass::rec(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q)
{
    while(this->items().size()>CountOfItems){QGraphicsItem*I = this->items().first();this->removeItem(I);}

    if(prX>newX && prY>newY)this->addRect(QRectF(QPointF(newX, newY), QSize(prX-newX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY>prY)this->addRect(QRectF(QPointF(prX, prY), QSize(newX-prX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX>prX && newY<prY)this->addRect(QRectF(QPointF(prX, newY), QSize(newX-prX, prY-newY)), QPen(Qt::NoPen), QBrush(Q));
    else if(newX<prX && newY>prY)this->addRect(QRectF(QPointF(newX, prY), QSize(prX-newX, newY-prY)), QPen(Qt::NoPen), QBrush(Q));


}

void SceneClass::ell(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q)
{
    while(this->items().size()>CountOfItems){QGraphicsItem*I = this->items().first();this->removeItem(I);}

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

    if(x1>CurrentPixmap.width())
    {
        x1 = CurrentPixmap.width();
        x2 = CurrentPixmap.width()-F.width();
    }
    if(y1>CurrentPixmap.height())
    {
        y1 = CurrentPixmap.height();
        y2 = CurrentPixmap.height()-F.height();
    }
    if(x1<0)
    {
        x1 = 0;
        x2 = F.width();
    }
    if(y1<0)
    {
        y1 = 0;
        y2 = F.height();
    }

    if(x2>CurrentPixmap.width())
    {
        x2 = CurrentPixmap.width();
        x1 = CurrentPixmap.width()-F.width();
    }
    if(y2>CurrentPixmap.height())
    {
        y2 = CurrentPixmap.height();
        y1 = CurrentPixmap.height()-F.height();
    }
    if(x2<0)
    {
        x2 = 0;
        x1 = F.width();
    }
    if(y2<0)
    {
        y2 = 0;
        y1 = F.height();
    }

//if(x1<=CurrentPixmap.width()&&x1>=0&&x2<=CurrentPixmap.width()&&x2>=0&&y1<=CurrentPixmap.height()&&y1>=0&&y2<=CurrentPixmap.height()&&y2>=0)
//{
    if(IsRect) rec(x1, y1, x2, y2, Q);
    else ell(x1, y1, x2, y2, Q);
//}



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

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && firstredraw&& !firstmove && !FirstRect && !FirstEllipse)
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

    else if(QApplication::keyboardModifiers()==Qt::ShiftModifier && firstmove && !firstredraw && !FirstRect && !FirstEllipse)shiftmoveadd(newX, newY);
    else if(RectMODE && FirstRect && !firstredraw && !firstmove&& QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)rec(prX, prY, newX, newY, COLOR);
    else if(CircleMODE && FirstEllipse && !firstredraw && !firstmove&& QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)ell(prX, prY, newX, newY, COLOR);

   /*

    */


    }
}
void SceneClass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QTextStream out(stdout);
    out<<CountOfItems<<"  "<<this->items().size()<<endl;

    if(QApplication::keyboardModifiers()==Qt::ControlModifier && IsWorkSpace &&firstredraw&&!firstmove&&!FirstEllipse && !FirstRect)
        {
            ++CountOfItems;
            firstredraw=false;
            this->clearSelection();
            IsModified=true;
            this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
            this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);
        }
    else if(QApplication::keyboardModifiers()==Qt::ShiftModifier && IsWorkSpace&&firstmove&&!FirstEllipse && !FirstRect&&!firstredraw)
    {
        ++CountOfItems;
        this->clearSelection();
        IsModified=true;
        firstmove=false;
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
        this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);
    }
    else if(RectMODE && FirstRect && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)
    {
    FirstRect=false;
    ++CountOfItems;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsRectItem::ItemIsMovable);

    }
    else if(CircleMODE &&FirstEllipse && !firstredraw && !firstmove && QApplication::keyboardModifiers()!=Qt::ControlModifier && QApplication::keyboardModifiers()!=Qt::ShiftModifier && QApplication::keyboardModifiers()!=Qt::MetaModifier)
    {
    FirstEllipse=false;
    ++CountOfItems;
    IsModified=true;
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsSelectable);
    this->items().first()->setFlag(QGraphicsEllipseItem::ItemIsMovable);

    }


    /**/


}



SceneClass::~SceneClass()
{

}
