#ifndef RECTTOOL_H
#define RECTTOOL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QTextStream>


#include "sceneclass.h"

class RectTool : public QMainWindow
{
    Q_OBJECT


public:
    explicit RectTool(QMainWindow *parent = nullptr);


    QPushButton *B;

    bool UP = false;

signals:

public slots:

    void SetUP();
    void Press(qreal x, qreal y, SceneClass *sc);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc);
};

#endif // RECTTOOL_H