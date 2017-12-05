#ifndef GRAPHICSVIEWCLASS_H
#define GRAPHICSVIEWCLASS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>

class GraphicsViewClass : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsViewClass(QWidget *parent = nullptr);
    ~GraphicsViewClass();

    QGraphicsScene* scene;

    int CountOfZoom = 0;
    double scaleFactor = 1.07;

    void CreateNew(int X, int Y);

signals:

public slots:
    //ZOOM
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);
    void ActualPixelsPressed();
    void FitScreenPressed();
    //ZOOM


};

#endif // GRAPHICSVIEWCLASS_H
