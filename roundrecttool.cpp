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
        IT = new QGraphicsPixmapItem(CreatePixmap(1+WID->PenWIDTH*3, 1+WID->PenWIDTH*3, 1.0, 1.0));
        IT->setPos(x, y);
        sc->addItem(IT);
        draw = true;
   }
}

void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        IT->setPixmap(CreatePixmap(abs(prX-newX)+WID->PenWIDTH*3, abs(prY-newY)+WID->PenWIDTH*3, abs(prX-newX), abs(prY-newY)));
        IT->setPos(std::min(prX, newX), std::min(prY, newY));
    }
}

QPixmap RoundRectTool::CreatePixmap(qreal x, qreal y, qreal a, qreal b)
{
    QPixmap bm(x, y);
    bm.fill(Qt::transparent);
    QPainter p(&bm);
    if(WID->PenWIDTH>0)p.setPen(WID->ReturnPen());
    else p.setPen(Qt::NoPen);
    p.setBrush(WID->ReturnBrush());
    p.setOpacity(WID->OPACITY);

    p.drawRoundRect(WID->PenWIDTH, WID->PenWIDTH,  a, b, 25, 25);

    setMask(bm);
    return bm;
}

void RoundRectTool::Release()
{
    draw = false;
}
