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
    connect(scene, SIGNAL(Release(qreal, qreal)), this, SLOT(Release()));


    WID = W;
    sc = scene;
}

void RoundRectTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(UP)
    {
        WID->RoundWIDGET->show();
        emit TurnOffAllOthers(3);
    }
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
        it->dx = 10;
        it->dy = 10;
        it->SetYX(x, y);
        sc->addItem(it);

        sc->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable, true);

        draw = true;
   }
}

void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        it->SetParameters();
        it->dx = abs(newX-prX);
        it->dy = abs(newY-prY);        

        qreal B = (it->ANGLE*M_PI/360)+atan(it->dy/it->dx);
        qreal Z = 2*sqrt(it->dy*it->dy+it->dx*it->dx)*sin(it->ANGLE*M_PI/360);
        if(newX-prX<0 && newY-prY<0)it->SetYX(std::min(prX,newX)+Z*sin(B), std::min(prY, newY)-Z*cos(B));
        else if(newX-prX<0 && newY-prY>0)it->SetYX(std::min(prX,newX)+it->dx-it->dx*cos(it->ANGLE*M_PI/180), std::min(prY, newY)-it->dx*sin(it->ANGLE*M_PI/180));
        else if(newX-prX>0 && newY-prY<0)it->SetYX(std::min(prX,newX)+it->dy*sin(it->ANGLE*M_PI/180), std::min(prY, newY)+it->dy-it->dy*cos(it->ANGLE*M_PI/180));
        else it->SetYX(std::min(prX,newX), std::min(prY, newY));
    }
}



void RoundRectTool::Release()
{
    draw = false;
}
