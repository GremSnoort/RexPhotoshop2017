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
#include "item.h"
#include "commonwidget.h"

class RoundRectTool : public QMainWindow
{
    Q_OBJECT
public:
    explicit RoundRectTool(QMainWindow *parent = nullptr, CommonWidget *W = nullptr, SceneClass *scene = nullptr);
    CommonWidget *WID;
    SceneClass *sc;

    QPushButton *B;


    Item *it;


    bool UP = false;
    bool draw = false;



signals:
    void TurnOffAllOthers(int N);

public slots:

    void SetUP();
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();    
};

#endif // ROUNDRECTTOOL_H
