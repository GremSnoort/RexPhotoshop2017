#include "recttool.h"

RectTool::RectTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QMainWindow(parent)
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



void RectTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        QGraphicsRectItem*R = new QGraphicsRectItem(x, y, 1, 1);

        //pen.setStyle(Qt::DashLine);
        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            R->setPen(pen);
        }else R->setPen(Qt::NoPen);
        R->setBrush(QBrush(WID->BrushCOLOR));
        sc->addItem(R);

        sc->it->R = R;
        sc->it->type = 1;
        sc->ItemsList->push_back(sc->it);

        draw = true;



   }
}
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {

        sc->ItemsList->last()->R->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
    }
}

void RectTool::Release()
{
    draw = false;
}
