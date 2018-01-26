#ifndef ITEMELL_H
#define ITEMELL_H

#include <QObject>
#include <QWidget>
#include "itembaseclass.h"

class ItemEll : public ItemBaseClass
{
    Q_OBJECT
public:
    explicit ItemEll();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    QRectF boundingRect() const;

signals:

public slots:
};
#endif // ITEMELL_H
