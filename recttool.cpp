#include "recttool.h"

RectTool::RectTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/SquareAppleV2.png")));
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
        R = new QGraphicsRectItem(x, y, 1, 1);
        if(WID->PenWIDTH!=0)R->setPen(WID->ReturnPen());
        R->setBrush(WID->ReturnBrush());
        R->setOpacity(WID->OPACITY);
        sc->addItem(R);

        draw = true;

   }
}
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
        R->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
}

void RectTool::Release()
{
    draw = false;
}
