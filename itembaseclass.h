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
    explicit ItemBaseClass();
    ~ItemBaseClass();

    static PenWidget *PWID;
    static BrushWidget *BWID;
    static RoundCornersWidget *RWID;

    QPen pen;
    int PenWIDTH;
    qreal OPACITY;
    int ANGLE = 0;

    QBrush brush;

    int RoundX;
    int RoundY;

    qreal x;
    qreal y;
    qreal dx = 1;
    qreal dy = 1;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr)
    {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }

    virtual QRectF boundingRect() const {return QRectF();}    
    void SetYX(qreal xx, qreal yy);

public slots:
    void SetParameters();

};
#endif // ITEMBASECLASS_H
