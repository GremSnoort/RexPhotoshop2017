#include "recttool.h"

RectTool::RectTool(QMainWindow *parent) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));

    B->adjustSize();
    B->move(10, 290);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
}

void RectTool::SetUP()
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

void RectTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QGraphicsRectItem*R = new QGraphicsRectItem(x, y, 10, 10);
        R->setPen(QPen(Qt::black));
        R->setBrush(QBrush(QColor(134, 234, 234)));
        sc->addItem(R);

        sc->it->R = R;
        sc->it->type = 1;
        sc->ItemsList->push_back(sc->it);

   }
}
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc)
{
    if(UP)
    {
        QTextStream out(stdout);
        out<<"!!!"<<endl;

        sc->ItemsList->last()->R->setRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
    }
}
