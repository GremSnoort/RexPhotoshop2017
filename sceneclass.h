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



    QPixmap CurrentPixmap;

    bool FirstRect = false;
    bool FirstEllipse = false;


    int CountOfItems = 0;

    QColor COLOR = QColor(255, 255, 255);

    //MODE
    bool RectMODE = false;
    bool CircleMODE = false;
    bool ZoomMODE = false;

    //MODE

signals:

public slots:
};

#endif // SCENECLASS_H
