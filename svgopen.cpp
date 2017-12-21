#include "svgopen.h"


SVGOpen::SVGOpen()
{
    T = new QList<QTransform>();
}

QList<QGraphicsEllipseItem *> SVGOpen::getEllipseElements(const QString filename)
{

    QList<QGraphicsEllipseItem *> itmList;
    T = new QList<QTransform>();


    QDomDocument doc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return itmList;
    QDomNodeList gList = doc.elementsByTagName("g");

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);

        QDomElement ellipse = gNode.firstChildElement("ellipse");

    if (ellipse.isNull()){
        continue;
    } else {

        QGraphicsEllipseItem *ell = new QGraphicsEllipseItem();

        ell->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

        QDomElement gElement = gNode.toElement();
        ell = new QGraphicsEllipseItem(atof(ellipse.attribute("cx").toStdString().c_str())-atof(ellipse.attribute("rx").toStdString().c_str()),
                      atof(ellipse.attribute("cy").toStdString().c_str())-atof(ellipse.attribute("ry").toStdString().c_str()),
                      2*atof(ellipse.attribute("rx").toStdString().c_str()),
                      2*atof(ellipse.attribute("ry").toStdString().c_str()));


        QColor fillColor(gElement.attribute("fill", "#ffffff"));
        fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
        ell->setBrush(QBrush(fillColor));


        QColor strokeColor(gElement.attribute("stroke", "#000000"));
        strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

        ell->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));

        //addition for transform
/*

        QString matrixstr(gElement.attribute("transform"));
        QList<QString> data = {"", "", "", "", "", ""};
        QList<qreal> values = {0, 0, 0, 0, 0, 0};

        int u=0;
        for(int i=7; i<matrixstr.size(); i++)
        {
            if(matrixstr[i]!=',' && matrixstr[i]!=')')data[u]+=matrixstr[i];
            else
            {
                values[u]=atof(data[u].toStdString().c_str());
                u++;
            }
        }

        QTransform t(values[0], values[1], values[2], values[3], values[4], values[5]);
        T->append(QTransform (values[0], values[1], values[2], values[3], values[4], values[5]));

        ell->setTransform(t);

*/

        //______________________

        itmList.append(ell);
    }

    }
    file.close();
    return itmList;
}

QList<QGraphicsRectItem *> SVGOpen::getRectElements(const QString filename)
{
    QList<QGraphicsRectItem *> itmList;
    T = new QList<QTransform>();



    QDomDocument doc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return itmList;
    QDomNodeList gList = doc.elementsByTagName("g");

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement rectangle = gNode.firstChildElement("rect");

        if (rectangle.isNull()){
            continue;
        } else {

            QGraphicsRectItem *rect = new QGraphicsRectItem();

            rect->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

            QDomElement gElement = gNode.toElement();
            rect->setRect(rectangle.attribute("x").toInt(),
                          rectangle.attribute("y").toInt(),
                          rectangle.attribute("width").toInt(),
                          rectangle.attribute("height").toInt());


            QColor fillColor(gElement.attribute("fill", "#ffffff"));
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
            rect->setBrush(QBrush(fillColor));


            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));

            //addition for transform
/*

            QString matrixstr(gElement.attribute("transform"));
            QList<QString> data = {"", "", "", "", "", ""};
            QList<qreal> values = {0, 0, 0, 0, 0, 0};

            int u=0;
            for(int i=7; i<matrixstr.size(); i++)
            {
                if(matrixstr[i]!=',' && matrixstr[i]!=')')data[u]+=matrixstr[i];
                else
                {
                    values[u]=atof(data[u].toStdString().c_str());
                    u++;
                }
            }

            QTransform t(values[0], values[1], values[2], values[3], values[4], values[5]);
            T->append(QTransform (values[0], values[1], values[2], values[3], values[4], values[5]));

            rect->setTransform(t);


*/
            //______________________

            itmList.append(rect);
        }


    }
    file.close();
    return itmList;
}

QRectF SVGOpen::getSizes(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return QRectF(0,0,700,700);


    QDomNodeList list = doc.elementsByTagName("svg");
    if(list.length() > 0) {
        QDomElement svgElement = list.item(0).toElement();
        QStringList parameters = svgElement.attribute("viewBox").split(" ");
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    return QRectF(0,0,700,700);
}
