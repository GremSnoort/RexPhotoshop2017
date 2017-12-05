#include "graphicsviewclass.h"

GraphicsViewClass::GraphicsViewClass(QWidget *parent) : QGraphicsView(parent)
{
    scene=new QGraphicsScene();
    this->setScene(scene);
}

//NEW

void GraphicsViewClass::CreateNew(int X, int Y)
{
    QPixmap tmppixmap = QPixmap(X, Y);
    tmppixmap.fill(QColor(255,255,255));
    scene=new QGraphicsScene();
    scene->addPixmap(tmppixmap);
    this->setScene(scene);
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
//ZOOM

GraphicsViewClass::~GraphicsViewClass()
{

}
