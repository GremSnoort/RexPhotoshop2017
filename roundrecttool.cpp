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
}



void RoundRectTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        bm = new QPixmap(1+WID->PenWIDTH*3, 1+WID->PenWIDTH*3);
        bm->fill(Qt::transparent);


        QPainter p(bm);


        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            p.setPen(pen);
        }else
            p.setPen(Qt::NoPen);

        p.setBrush(QBrush(WID->BrushCOLOR));

        p.drawRoundRect(WID->PenWIDTH, WID->PenWIDTH, 1, 1, 25, 25);

        setMask(*bm);

        QGraphicsPixmapItem *pixm = new QGraphicsPixmapItem(*bm);
        pixm->setPos(x, y);
        pixm->setOpacity(WID->OPACITY);
        sc->addItem(pixm);



        draw = true;


   }
}
void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {

        //dynamic_cast<QGraphicsPixmapItem*>(sc->items().first())->pixmap() = QPixmap(abs(prX-newX)+WID->PenWIDTH*3, abs(prY-newY)+WID->PenWIDTH*3);
        bm = new QPixmap(abs(prX-newX)+WID->PenWIDTH*3, abs(prY-newY)+WID->PenWIDTH*3);
        bm->fill(Qt::transparent);
        //dynamic_cast<QGraphicsPixmapItem*>(sc->items().first())->pixmap().fill(Qt::transparent);

        QPainter p(bm);
        if(WID->PenWIDTH>0){
            pen.setWidth(WID->PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(WID->PenCOLOR);
            p.setPen(pen);
        }else p.setPen(Qt::NoPen);
        p.setBrush(QBrush(WID->BrushCOLOR));

        p.drawRoundRect(WID->PenWIDTH, WID->PenWIDTH,  abs(prX-newX), abs(prY-newY), 25, 25);


        setMask(*bm);

        //sc->items().removeFirst();
        /*QGraphicsPixmapItem * pixm = new QGraphicsPixmapItem(*bm);
        pixm->setPos(std::min(prX, newX), std::min(prY, newY));
        pixm->setOpacity(WID->OPACITY);
        sc->items().first() = pixm;*/


    }
}

void RoundRectTool::Release()
{
    draw = false;
}
