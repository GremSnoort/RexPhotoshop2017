#ifndef SVGOPEN_H
#define SVGOPEN_H


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
    static QList<QGraphicsRectItem *> getRectElements(const QString filename);
    static QList<QGraphicsEllipseItem *> getEllipseElements(const QString filename);
    static QRectF getSizes(const QString filename);
};


#endif // SVGOPEN_H
