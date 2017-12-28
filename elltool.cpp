#include "elltool.h"

EllTool::EllTool(QMainWindow *parent) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));

    B->adjustSize();
    B->move(10, 360);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
}

void EllTool::SetUP()
{
    if(!UP)
    {
        B->clearFocus();
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        UP = true;
    }else
    {
        B->clearFocus();
        B->setStyleSheet("");
        UP = false;
    }
}

void EllTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QGraphicsEllipseItem*E = new QGraphicsEllipseItem(x, y, 10, 10);
        E->setPen(QPen(Qt::black));
        E->setBrush(QBrush(QColor(134, 234, 234)));
        sc->addItem(E);

        sc->it->E = E;
        sc->it->type = 2;
        sc->ItemsList->push_back(sc->it);

   }
}
void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc)
{
    if(UP)
    {
        sc->ItemsList->last()->E->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
    }
}
