#ifndef ELLTOOL_H
#define ELLTOOL_H


#include <QLabel>
#include <QSlider>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTextStream>

#include <QColorDialog>
#include "sceneclass.h"
#include "graphicsitemclass.h"
#include "commonwidget.h"

class EllTool : public QObject
{
    Q_OBJECT
public:
    explicit EllTool(QMainWindow *parent = nullptr, CommonWidget*W = nullptr, SceneClass *scene = nullptr);

    CommonWidget*WID;
    SceneClass *sc;
    QGraphicsEllipseItem*E;

    QPushButton *B;


    bool UP = false;
    bool draw = false;

signals:

public slots:

    void SetUP();
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();
};

#endif // ELLTOOL_H
