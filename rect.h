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

class Rect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Rect(QRectF F, QPen P, QBrush B, qreal O);

    QGraphicsRectItem* RECTANGLE;

signals:

public slots:
};

#endif // RECT_H
