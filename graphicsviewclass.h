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
#include <QCursor>

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
    double sF = 1.07;

    void CreateNew();



private:



signals:

public slots:

    ///ZOOM
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);

    void RectChanges(QRectF R);


};

#endif // GRAPHICSVIEWCLASS_H
