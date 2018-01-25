#ifndef ITEMBASECLASS_H
#define ITEMBASECLASS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QPoint>

#include "penwidget.h"
#include "brushwidget.h"
#include "roundcornerswidget.h"

class ItemBaseClass : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ItemBaseClass(PenWidget *PW = 0, BrushWidget *BW = 0, RoundCornersWidget *RW = 0);
    ~ItemBaseClass();

    PenWidget *PWID;
    BrushWidget *BWID;
    RoundCornersWidget *RWID;

    QPen pen;
    int PenWIDTH;
    qreal OPACITY;
    int ANGLE = 0;

    QBrush brush;

    int RoundX;
    int RoundY;

    qreal x;
    qreal y;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr){}
    virtual QRectF boundingRect() const {return QRectF();}    
    void SetYX(qreal xx, qreal yy);

public slots:
    void SetParameters();

};
#endif // ITEMBASECLASS_H
