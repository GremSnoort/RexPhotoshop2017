#ifndef SVGOPEN_H
#define SVGOPEN_H

#include <QTextStream>
#include <QList>
#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class SVGOpen
{
public:
    SVGOpen();

    QList<QTransform> *T;

    QList<QGraphicsRectItem *> getRectElements(const QString filename);
    QList<QGraphicsEllipseItem *> getEllipseElements(const QString filename);
    QRectF getSizes(const QString filename);


};


#endif // SVGOPEN_H
