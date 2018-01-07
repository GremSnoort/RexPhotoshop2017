#include "recttool.h"

RectTool::RectTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 75);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release()), this, SLOT(Release()));

    WID = W;
    sc = scene;
}

void RectTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
}

void RectTool::Press(qreal x, qreal y)
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
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        it->SetYX(prX, prY);
        it->dx = newX-prX;
        it->dy = newY-prY;        
    }
}

void RectTool::Release()
{

    draw = false;

}
