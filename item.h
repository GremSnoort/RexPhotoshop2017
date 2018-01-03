#ifndef ITEM_H
#define ITEM_H


#include <QGraphicsItem>
#include <QPainter>

#include "commonwidget.h"

class Item : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = 0, CommonWidget*W = 0);
    ~Item();


    CommonWidget *WID;
    qreal a;
    qreal b;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


};

#endif // ITEM_H
