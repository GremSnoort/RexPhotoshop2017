#include "graphicsviewclass.h"

GraphicsViewClass::GraphicsViewClass(QWidget *parent) : QGraphicsView(parent)
{
    scene=new SceneClass();
    this->setScene(scene);

}


void GraphicsViewClass::SetColor(QColor q)
{
    scene->COLOR=q;
}


///NEW
void GraphicsViewClass::CreateNew()
{
    scene = new SceneClass();
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    this->setScene(scene);
}



///ZOOM
void GraphicsViewClass::zoomUpEvent(bool)
{
    if(CountOfZoom<60){
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this-> scale(scaleFactor, scaleFactor);
    CountOfZoom++;
    }
}
void GraphicsViewClass::zoomDownEvent(bool)
{
    if(CountOfZoom>(-60)){
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    CountOfZoom--;
    }
}



GraphicsViewClass::~GraphicsViewClass()
{

}
