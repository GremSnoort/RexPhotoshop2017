#ifndef RECTTOOL_H
#define RECTTOOL_H

#include <QLabel>
#include <QPen>
#include <QSlider>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTextStream>
#include <QColorDialog>
#include <QColor>

#include "sceneclass.h"
#include "graphicsitemclass.h"
#include "commonwidget.h"

class RectTool : public QObject
{
    Q_OBJECT


public:
    explicit RectTool(QMainWindow *parent = nullptr, CommonWidget *W = nullptr, SceneClass *scene = nullptr);


    CommonWidget *WID;
    SceneClass *sc;

    QPushButton *B;    

    QGraphicsRectItem*R;


    bool UP = false;
    bool draw = false;

signals:

public slots:

    void SetUP();
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();

};

#endif // RECTTOOL_H
