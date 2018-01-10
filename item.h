#ifndef ITEM_H
#define ITEM_H


#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QPoint>

#include "commonwidget.h"

class Item : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = 0, CommonWidget*W = 0);
    ~Item();

    int T = 1;

    QPen pen;
    QBrush brush;
    qreal OPACITY;
    int PenWIDTH;
    int RoundX;
    int RoundY;
    int ANGLE = 0;

    QPolygonF points = QPolygonF();


    CommonWidget *WID;

    qreal x;
    qreal y;
    qreal dx = 1;
    qreal dy = 1;



    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

    void SetParameters();
    void SetYX(qreal xx, qreal yy);

};

#endif // ITEM_H
