#ifndef ELLTOOL_H
#define ELLTOOL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTextStream>


#include "sceneclass.h"

class EllTool : public QMainWindow
{
    Q_OBJECT
public:
    explicit EllTool(QMainWindow *parent = nullptr);

    QPushButton *B;

    bool UP = false;

signals:

public slots:

    void SetUP();
    void Press(qreal x, qreal y, SceneClass *sc);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc);
};

#endif // ELLTOOL_H
