#include "recttool.h"

RectTool::RectTool(QMainWindow *parent) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 290);
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

    CDPen = new QColorDialog(parent);
    CDPen->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDPen, SIGNAL(colorSelected(QColor)), this, SLOT(SetPenColor(QColor)));

    CDBrush = new QColorDialog(parent);
    CDBrush->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDBrush, SIGNAL(colorSelected(QColor)), this, SLOT(SetBrushColor(QColor)));

    connect(PenColor, SIGNAL(released()), CDPen, SLOT(show()));
    connect(BrushColor, SIGNAL(released()), CDBrush, SLOT(show()));



    PenColor->hide();
    BrushColor->hide();

}

void RectTool::SetUP()
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

void RectTool::SetPenColor(QColor Q)
{
    PenCOLOR = Q;
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
}
void RectTool::SetBrushColor(QColor Q)
{
    BrushCOLOR = Q;
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
}

void RectTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QGraphicsRectItem*R = new QGraphicsRectItem(x, y, 10, 10);
        QPen pen;
        //pen.setStyle(Qt::DashLine);
        pen.setWidth(5);
        pen.setColor(PenCOLOR);
        R->setPen(pen);
        R->setBrush(QBrush(BrushCOLOR));
        sc->addItem(R);

        sc->it->R = R;
        sc->it->type = 1;
        sc->ItemsList->push_back(sc->it);

        draw = true;



   }
}
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc)
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
