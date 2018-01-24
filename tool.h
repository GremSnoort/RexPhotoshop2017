#ifndef TOOL_H
#define TOOL_H

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


#include "penwidget.h"
#include "brushwidget.h"
#include "roundcornerswidget.h"


class Tool : public QObject
{
    Q_OBJECT
public:
    explicit Tool(QMainWindow *parent = nullptr);




    PenWidget *PenWID;
    BrushWidget *BrWID;
    RoundCornersWidget *RcWID;

    virtual void Press(qreal x, qreal y){}
    virtual void Move(qreal newX, qreal newY, qreal prX, qreal prY){}
    virtual void Release(){}

signals:
    void ToolSignal(int i);

public slots:
    virtual void EmitSignal(){}

};

#endif // TOOL_H
