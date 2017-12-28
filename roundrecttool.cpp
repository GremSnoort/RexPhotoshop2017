#include "roundrecttool.h"

RoundRectTool::RoundRectTool(QMainWindow *parent) : QMainWindow(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/rounded-rectangle.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 215);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));



    PenColor = new QPushButton(parent);
    PenColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/PEN1.png")));
    PenColor->setIconSize(QSize(50, 50));
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
    PenColor->adjustSize();
    PenColor->move(1420, 75);
    PenColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    BrushColor = new QPushButton(parent);
    BrushColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(1420, 145);
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

void RoundRectTool::SetUP()
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

void RoundRectTool::SetPenColor(QColor Q)
{
    PenCOLOR = Q;
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
}
void RoundRectTool::SetBrushColor(QColor Q)
{
    BrushCOLOR = Q;
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
}

void RoundRectTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QPixmap bm(10, 10);
        bm.fill(Qt::transparent);


        QPainter p(&bm);
        QPen pen;
        //pen.setStyle(Qt::DashLine);
        pen.setWidth(5);
        pen.setColor(PenCOLOR);
        p.setPen(pen);
        p.setBrush(QBrush(BrushCOLOR));

        p.drawRoundRect(0, 0, 10, 10, 25, 25);

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
void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc)
{
    if(UP&&draw)
    {

        QPixmap bm(abs(prX-newX), abs(prY-newY));
        bm.fill(Qt::transparent);

        QPainter p(&bm);
        QPen pen;
        //pen.setStyle(Qt::DashLine);
        pen.setWidth(5);
        pen.setColor(PenCOLOR);
        p.setPen(pen);
        p.setBrush(QBrush(BrushCOLOR));

        p.drawRoundRect(0, 0,  abs(prX-newX), abs(prY-newY), 25, 25);


        setMask(bm);

        sc->ItemsList->last()->P->setPixmap(bm);
        sc->ItemsList->last()->P->setPos(std::min(prX, newX), std::min(prY, newY));




    }
}

void RoundRectTool::Release()
{
    draw = false;
}
