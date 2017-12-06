#include "graphicsviewclass.h"

GraphicsViewClass::GraphicsViewClass(QWidget *parent) : QGraphicsView(parent)
{
    scene=new SceneClass();
    this->setScene(scene);
}



void GraphicsViewClass::SetRectMode()
{

    scene->RectMODE=true;
}


//NEW

void GraphicsViewClass::CreateNew(int X, int Y)
{


    QTextStream out(stdout);
    QPixmap tmppixmap = QPixmap(X, Y);
    tmppixmap.fill(QColor(255,255,255));
    scene = new SceneClass();
    scene->addPixmap(tmppixmap);
    scene->CountOfItems+=1;

    this->setScene(scene);
   \
    scene->CurrentPixmap = tmppixmap;


    out<<scene->items().size()<<endl;


    //out<<scene->items().at(0)->boundingRect().center().rx()<<"  "<<scene->items().at(0)->boundingRect().center().ry()<<"  "<<items().at(0)->boundingRect().bottomLeft().rx()<<endl;
}


//NEW

//ZOOM
void GraphicsViewClass::zoomUpEvent(bool)
{
    if(CountOfZoom<30){
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this-> scale(scaleFactor, scaleFactor);
    CountOfZoom++;
    }
}

void GraphicsViewClass::zoomDownEvent(bool)
{
    if(CountOfZoom>(-30)){
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    CountOfZoom--;
    }
}

void GraphicsViewClass::ActualPixelsPressed()
{

    if(CountOfZoom>0)
    {
        this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        for(int i=0; i<abs(CountOfZoom); i++)
        {
            this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
        CountOfZoom=0;
    }
    else if(CountOfZoom<0)
    {
        this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        for(int i=0; i<abs(CountOfZoom); i++)
        {
            this-> scale(scaleFactor, scaleFactor);
        }
        CountOfZoom=0;
    }


}

void GraphicsViewClass::FitScreenPressed()
{
    if(scene->height()>0 &&  scene->width()>0){
    ActualPixelsPressed();
    if(scene->height()>=scene->width())
    {
        double Z = scene->height();
        if(scene->height()>=this->size().height()) //8888888
        {
            while(Z>this->size().height())
            {
                    Z/=scaleFactor;
                    CountOfZoom--;
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
            }
        }else//scene->height()<ui->graphicsView->size().height()
        {
            while(true)
            {
                    Z*=scaleFactor;
                    CountOfZoom++;
                    if(Z>=this->size().height())
                    {
                        Z/=scaleFactor;
                        CountOfZoom--;
                        break;
                    }
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                this->scale(scaleFactor,  scaleFactor);
            }
        }
    }
    else
    {

        double Z = scene->width();

        if(scene->width()>this->size().width()) //8888888
        {
            while(Z>this->size().width())
            {
                    Z/=scaleFactor;
                    CountOfZoom--;
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
            }
        }else//scene->height()<ui->graphicsView->size().height()
        {
            while(true)
            {
                    Z*=scaleFactor;
                    CountOfZoom++;
                    if(Z>=this->size().width())
                    {
                        Z/=scaleFactor;
                        CountOfZoom--;
                        break;
                    }
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                this->scale(scaleFactor,  scaleFactor);
            }
        }

    }
  }
}
//ZOOM

GraphicsViewClass::~GraphicsViewClass()
{

}
