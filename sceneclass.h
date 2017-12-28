#ifndef SCENECLASS_H
#define SCENECLASS_H

#define private public


#include <QPixmap>
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
        int type;
        QGraphicsRectItem*R;
        QGraphicsEllipseItem*E;
        QGraphicsPixmapItem*P;
        all_items()
        {
            type = 0;
            R = new QGraphicsRectItem();
            E = new QGraphicsEllipseItem();
            P = new QGraphicsPixmapItem();
        }
    };

    all_items*it;

    QList<all_items*> *ItemsList;

    QGraphicsScene* scene;


    QPointF     previousPoint;

    bool IsModified = false;


    QColor COLOR = QColor(255, 255, 255);






signals:
    void Press(qreal x, qreal y, SceneClass*sc);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass*sc);
    void Release();

public slots:


};

#endif // SCENECLASS_H
