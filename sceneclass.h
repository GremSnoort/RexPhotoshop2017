#ifndef SCENECLASS_H
#define SCENECLASS_H

#define private public

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QTextStream>
#include <QPixmap>

class SceneClass : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SceneClass(QObject *parent = nullptr);
    ~SceneClass();

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QPointF     previousPoint;

    QGraphicsScene* scene;

    void MakeNew(int X, int Y);

    QPixmap CurrentPixmap;

    bool FirstRect = false;
    int CountOfItems = 0;

    //MODE
    bool RectMODE = false;

    //MODE

signals:

public slots:
};

#endif // SCENECLASS_H
