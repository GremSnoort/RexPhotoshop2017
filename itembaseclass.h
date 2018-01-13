#ifndef ITEMBASECLASS_H
#define ITEMBASECLASS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QPoint>

#include "penwidget.h"

class ItemBaseClass : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ItemBaseClass(QObject *parent = 0);
    ~ItemBaseClass();

    QPen pen;
    int PenWIDTH;
    qreal OPACITY;
    int ANGLE = 0;

    void SetCommonParameters(PenWidget*PWID);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr){}
    virtual QRectF boundingRect() const {return QRectF();}
    virtual void SetParameters() {}
    virtual void SetYX(qreal xx, qreal yy){}

};
#endif // ITEMBASECLASS_H
