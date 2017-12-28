#ifndef ROUNDRECTTOOL_H
#define ROUNDRECTTOOL_H

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

#endif // ROUNDRECTTOOL_H
