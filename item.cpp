#include "item.h"


class Tool {
public:
};

class ToolRegistrator {
public:
    static QList<ToolRegistrator*> registry;
    ToolRegistrator(Tool *) {}
    virtual Tool *makeTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) =0;
};

Item::Item(QObject *parent, CommonWidget *W)
    : QObject(parent), QGraphicsItem()
{
    WID = W;    
}
Item::~Item()
{

}

void Item::SetParameters()
{
    OPACITY = WID->OPACITY;
    pen = WID->ReturnPen();
    brush = WID->ReturnBrush();
    PenWIDTH = WID->PenWIDTH;
    RoundX = WID->ROUNDCornersX;
    RoundY = WID->ROUNDCornersY;
    ANGLE = WID->ANGLE;
}

void Item::SetYX(qreal xx, qreal yy)
{
    x = yy*sin(ANGLE*M_PI/180) + xx*cos(ANGLE*M_PI/180);
    y = yy*cos(ANGLE*M_PI/180) - xx*sin(ANGLE*M_PI/180);    
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(PenWIDTH>0)painter->setPen(pen);
    else painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->setOpacity(OPACITY);    
    painter->rotate(ANGLE);

    if(T==3)painter->drawRoundRect(x, y, dx, dy, RoundX, RoundY);
    else if(T==1)painter->drawRect(x, y, dx, dy);
    else if(T==2)painter->drawEllipse(x, y, dx, dy);
    else if(T==0)
    {
        painter->setOpacity(1);
        painter->rotate(-ANGLE);
        painter->setPen(Qt::DashLine);
        painter->setBrush(QBrush(QColor(255, 255, 255, 0))); // semitransparent white

        QPainterPath path;
        path.addRect(x, y, dx, dy);

        painter->drawPath(path);
        update(path.boundingRect());
    }
    else if(T==4)
    {                
        painter->drawPolyline(points);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Item::boundingRect() const
{
    if(T==4)return points.boundingRect();
        else return QRectF(x, y, dx, dy);
}
