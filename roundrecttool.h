#ifndef ROUNDRECTTOOL_H
#define ROUNDRECTTOOL_H


#include <QLabel>
#include <QSlider>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTextStream>
#include <QBitmap>
#include <QGraphicsPixmapItem>
#include <QColorDialog>
#include "sceneclass.h"


class RoundRectTool : public QMainWindow
{
    Q_OBJECT
public:
    explicit RoundRectTool(QMainWindow *parent = nullptr);
    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(0, 100, 255);
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

#endif // ROUNDRECTTOOL_H
