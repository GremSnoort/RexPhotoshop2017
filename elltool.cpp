#include "elltool.h"

EllTool::EllTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{    
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 145);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release()), this, SLOT(Release()));

    WID = W;
    sc = scene;
}

void EllTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
}

void EllTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        it = new Item(0, WID);
        it->SetParameters();
        it->T = 2;
        it->x = x;
        it->y = y;
        sc->addItem(it);

        draw = true;
   }
}
void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        it->x = std::min(prX, newX);
        it->y = std::min(prY, newY);
        it->dx = abs(prX-newX);
        it->dy = abs(prY-newY);
    }
}

void EllTool::Release()
{
    draw = false;
}
