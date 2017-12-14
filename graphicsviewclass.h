#ifndef GRAPHICSVIEWCLASS_H
#define GRAPHICSVIEWCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QTextStream>

#include "sceneclass.h"

class GraphicsViewClass : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsViewClass(QWidget *parent = nullptr);
    ~GraphicsViewClass();

    SceneClass* scene;

    int CountOfZoom = 0;
    double scaleFactor = 1.07;

    void CreateNew(int X, int Y);



private:



signals:

public slots:
    //ZOOM
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);
    void ActualPixelsPressed();
    void FitScreenPressed();
    //ZOOM

    void SetRectMode();
    void SetCircleMode();
    void SetZoomMode();
    void SetRedrawRectMode(int i);
    void SetRedrawEllMode(int i);
    void SetColor(QColor q);



};

#endif // GRAPHICSVIEWCLASS_H
