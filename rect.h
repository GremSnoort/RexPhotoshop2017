#ifndef RECT_H
#define RECT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>
#include <QRectF>
#include <QList>

class Rect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Rect(QObject *parent = nullptr);
    ~Rect();

    QList<QGraphicsRectItem*> *Items;

    QGraphicsRectItem* RECTANGLE;

    void Update(QRectF F);
    QGraphicsRectItem* CreateNew(QRectF F, QPen P, QBrush B, qreal Opacity, qreal Angle);

signals:

public slots:
};

#endif // RECT_H
