#include "tool.h"

Tool::Tool(QObject *parent) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

void Tool::Press(qreal x, qreal y)
{
if(UP)
{
    it = new Item(0, WID);
    it->SetParameters();
    it->T = 1;
    it->SetYX(x, y);
    sc->addItem(it);

    sc->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable, true);


    draw = true;
}
}
void Tool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
if(UP&&draw)
{
    it->SetParameters();
    it->SetYX(prX, prY);
    it->dx = newX-prX;
    it->dy = newY-prY;
}
}

void Tool::Release()
{

}



