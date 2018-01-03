#include "elltool.h"

EllTool::EllTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{    
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/RoundAppleV2.png")));
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
        E = new QGraphicsEllipseItem(x, y, 1, 1);
        if(WID->PenWIDTH!=0)E->setPen(WID->ReturnPen());
        E->setBrush(WID->ReturnBrush());
        E->setOpacity(WID->OPACITY);

        sc->addItem(E);
        draw = true;

   }
}
void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)    
        E->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));

}

void EllTool::Release()
{
    draw = false;
}
