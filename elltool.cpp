#include "elltool.h"

EllTool::EllTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QMainWindow(parent)
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
    if(!UP)
    {
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        UP = true;
    }else
    {
        B->setStyleSheet("");
        UP = false;
    }
}




void EllTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        QGraphicsEllipseItem*E = new QGraphicsEllipseItem(x, y, 1, 1);

        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            E->setPen(pen);
        }else E->setPen(Qt::NoPen);
        E->setBrush(QBrush(WID->BrushCOLOR));
        E->setOpacity(WID->OPACITY);
        sc->addItem(E);

        sc->it->E = E;
        sc->it->type = 2;
        sc->ItemsList->push_back(sc->it);

        draw = true;

   }
}
void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        sc->ItemsList->last()->E->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
    }
}

void EllTool::Release()
{
    draw = false;
}
