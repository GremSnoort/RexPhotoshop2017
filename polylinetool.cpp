#include "polylinetool.h"

PolyLineTool::PolyLineTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/polyline.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 285);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release(qreal, qreal)), this, SLOT(Release(qreal, qreal)));


    WID = W;
    sc = scene;
}

void PolyLineTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(!UP)
        WID->BrushWIDGET->show();
    else
    {
        WID->BrushWIDGET->hide();
        if(UP)emit TurnOffAllOthers(4);
    }
}

void PolyLineTool::Press(qreal x, qreal y)
{
    if(UP)
    {

        it = new Item(0, WID);
        it->SetParameters();
        it->T = 4;
        it->points.clear();
        it->points<<QPoint(x, y);
        sc->addItem(it);
        sc->items().first()->setFlag(QGraphicsLineItem::ItemIsSelectable, true);

        draw = true;

   }
}
void PolyLineTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        if(del)it->points.removeLast();
        it->points<<QPoint(newX, newY);
        del = true;
    }
}

void PolyLineTool::Release(qreal newX, qreal newY)
{
    if(UP)
    {
        it->points<<QPoint(newX, newY);
        del = false;
        draw = false;
    }
}

