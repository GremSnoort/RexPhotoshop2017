#include "roundrecttool.h"

RoundRectTool::RoundRectTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/rounded-rectangle.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 215);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release()), this, SLOT(Release()));


    WID = W;
    sc = scene;
}

void RoundRectTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(UP)
        WID->RoundWIDGET->show();
    else
        WID->RoundWIDGET->hide();
}

void RoundRectTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        it = new Item(0, WID);
        it->SetParameters();
        it->T = 3;
        it->a = 1;
        it->b = 1;
        it->setPos(x, y);
        sc->addItem(it);

        draw = true;
   }
}

void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        it->a = newX-prX;
        it->b = newY-prY;
        it->setPos(prX, prY);
    }
}



void RoundRectTool::Release()
{
    draw = false;
}
