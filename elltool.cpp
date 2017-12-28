#include "elltool.h"

EllTool::EllTool(QMainWindow *parent) : QMainWindow(parent)
{    
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 360);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));

    PenColor = new QPushButton(parent);
    PenColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/PEN1.png")));
    PenColor->setIconSize(QSize(50, 50));
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
    PenColor->adjustSize();
    PenColor->move(1420, 125);
    PenColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    BrushColor = new QPushButton(parent);
    BrushColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(1420, 200);
    BrushColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    PenColor->hide();
    BrushColor->hide();
}

void EllTool::SetUP()
{
    if(!UP)
    {
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        UP = true;
        PenColor->show();
        BrushColor->show();
    }else
    {
        B->setStyleSheet("");
        UP = false;
        PenColor->hide();
        BrushColor->hide();
    }
}

void EllTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QGraphicsEllipseItem*E = new QGraphicsEllipseItem(x, y, 10, 10);
        E->setPen(QPen(PenCOLOR));
        E->setBrush(QBrush(BrushCOLOR));
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
