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

#include "itembaseclass.h"

class Tool : public QObject
{
    Q_OBJECT
public:
    explicit Tool(QMainWindow *parent = nullptr);

    QPushButton *B;

signals:

public slots:
    virtual void Press(qreal x, qreal y)
    {
        Q_UNUSED(x);
        Q_UNUSED(y);
    }
    virtual void Move(qreal newX, qreal newY, qreal prX, qreal prY)
    {
        Q_UNUSED(newX);
        Q_UNUSED(newY);
        Q_UNUSED(prX);
        Q_UNUSED(prY);
    }
    virtual void Release(){}
    virtual void ON(){}
    virtual void OFF(){}

};

#endif // TOOL_H
