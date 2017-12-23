#ifndef SCENECLASS_H
#define SCENECLASS_H

#define private public


#include "rect.h"
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


    struct all_items
    {
        QGraphicsRectItem*R;
        QGraphicsEllipseItem*E;
        all_items()
        {
            R = new QGraphicsRectItem(QRectF(0, 0, 1, 1));
            E = new QGraphicsEllipseItem(QRectF(0, 0, 1, 1));
        }
    };

    QList<all_items*> *ItemsList;

    Rect *itemsRECT;

    QGraphicsScene* scene;


    QPointF     previousPoint;
    bool IsModified = false;


    QColor COLOR = QColor(255, 255, 255);


    //MODE
    bool RectMODE = false;
    bool EllipseMODE = false;
    bool SelectMODE = false;


    //MODE






signals:
    void Press(QGraphicsSceneMouseEvent *event, SceneClass*sc);

public slots:


};

#endif // SCENECLASS_H
