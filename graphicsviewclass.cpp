#include "graphicsviewclass.h"

GraphicsViewClass::GraphicsViewClass(QWidget *parent) : QGraphicsView(parent)
{
    scene=new SceneClass();
    this->setScene(scene);
    this->setSceneRect(0,0, scene->WIDTH, scene->HEIGHT);
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    scene->clear();


    connect(scene, SIGNAL(sceneRectChanged(QRectF)), this, SLOT(RectChanges(QRectF)));

}

void GraphicsViewClass::RectChanges(QRectF R)
{
    this->setSceneRect(R);
}


///NEW
void GraphicsViewClass::CreateNew()
{
    scene->clear();
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));    
}



///ZOOM
void GraphicsViewClass::zoomUpEvent(bool)
{    
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this-> scale(scaleFactor, scaleFactor);
    CountOfZoom++;
}
void GraphicsViewClass::zoomDownEvent(bool)
{
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    CountOfZoom--;
}



GraphicsViewClass::~GraphicsViewClass()
{

}
