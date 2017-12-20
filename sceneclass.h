#ifndef SCENECLASS_H
#define SCENECLASS_H

#define private public


#include <QTransform>
#include <QAbstractGraphicsShapeItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QApplication>
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


    int CountOfItems;

    bool IsModified = false;
    bool IsWorkSpace = false;

    QColor COLOR = QColor(255, 255, 255);

    QRectF F;
    int I;
    QColor Q;

    //MODE
    bool RectMODE = false;
    bool CircleMODE = false;
    bool ZoomMODE = false;
    bool FillMODE = false;

    bool SelectMODE = false;

    bool firstmove = false;


    bool firstredraw = false;
    //MODE




    void rec(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q);
    void ell(qreal prX, qreal prY, qreal newX, qreal newY, QColor Q);

    void shiftmoveadd(qreal newX, qreal newY);
    void controlresize(qreal newX, qreal newY);

    void fill();
    QColor getColor(qreal newX, qreal newY);



signals:

public slots:


};

#endif // SCENECLASS_H
