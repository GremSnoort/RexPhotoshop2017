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

class RectTool : public QMainWindow
{
    Q_OBJECT


public:
    explicit RectTool(QMainWindow *parent = nullptr);

    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(0, 255, 0);
    int PenWIDTH = 0;

    QColorDialog* CDPen;
    QColorDialog* CDBrush;


    QWidget *WID;


    QPushButton *B;
    QPushButton *PenColor;
    QPushButton *BrushColor;

    QSlider *PenWidth;
    QLabel *LabelPenWIDTH;


    QPen pen;

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
    void SetPenWidth(int w);
};

#endif // RECTTOOL_H
