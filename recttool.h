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
#include <QColorDialog>
#include <QColor>
#include "sceneclass.h"

class RectTool : public QMainWindow
{
    Q_OBJECT


public:
    explicit RectTool(QMainWindow *parent = nullptr);

    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(255, 255, 255);

    QColorDialog* CDPen;
    QColorDialog* CDBrush;


    QPushButton *B;
    QPushButton *PenColor;
    QPushButton *BrushColor;

    bool UP = false;
    bool draw = false;

signals:

public slots:

    void SetUP();
    void Press(qreal x, qreal y, SceneClass *sc);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc);
    void Release();

    void SetPenColor(QColor Q);
    void SetBrushColor(QColor Q);
};

#endif // RECTTOOL_H
