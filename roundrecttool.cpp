#include "roundrecttool.h"

RoundRectTool::RoundRectTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/rounded-rectangle.png")));
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



void RoundRectTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        QPixmap bm(1+WID->PenWIDTH*3, 1+WID->PenWIDTH*3);
        bm.fill(Qt::transparent);


        QPainter p(&bm);

        //pen.setStyle(Qt::DashLine);
        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            p.setPen(pen);
        }else p.setPen(Qt::NoPen);

        p.setBrush(QBrush(WID->BrushCOLOR));

        p.drawRoundRect(WID->PenWIDTH, WID->PenWIDTH, 1, 1, 25, 25);

        setMask(bm);

        QGraphicsPixmapItem * pixm = new QGraphicsPixmapItem(bm);
        pixm->setPos(x, y);
        sc->addItem(pixm);

        sc->it->P = pixm;
        sc->it->type = 3;
        sc->ItemsList->push_back(sc->it);

        draw = true;


   }
}
void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {

        QPixmap bm(abs(prX-newX)+WID->PenWIDTH*3, abs(prY-newY)+WID->PenWIDTH*3);
        bm.fill(Qt::transparent);

        QPainter p(&bm);
        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            p.setPen(pen);
        }else p.setPen(Qt::NoPen);
        p.setBrush(QBrush(WID->BrushCOLOR));

        p.drawRoundRect(WID->PenWIDTH, WID->PenWIDTH,  abs(prX-newX), abs(prY-newY), 25, 25);


        setMask(bm);

        sc->ItemsList->last()->P->setPixmap(bm);
        sc->ItemsList->last()->P->setPos(std::min(prX, newX), std::min(prY, newY));




    }
}

void RoundRectTool::Release()
{
    draw = false;
}
