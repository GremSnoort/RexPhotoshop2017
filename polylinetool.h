#ifndef POLYLINETOOL_H
#define POLYLINETOOL_H

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

#include "item.h"
#include "sceneclass.h"


class PolyLineTool : public QObject
{
    Q_OBJECT
public:
    explicit PolyLineTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr);


    //CommonWidget *WID;
    SceneClass *sc;

    QPushButton *B;


    Item *it;
    bool del = false;


    bool UP = false;
    bool draw = false;
    bool drawFirst = true;


signals:
    void TurnOffAllOthers(bool state);

public slots:

    void SetUP();
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release(qreal newX, qreal newY);

    void TurnOnOff(bool state);
};

#endif // POLYLINETOOL_H
