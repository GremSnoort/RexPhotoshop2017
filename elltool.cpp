#include "elltool.h"

EllTool::EllTool(QMainWindow *parent) : QMainWindow(parent)
{    
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 145);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));


    WID = new QWidget(parent);
    WID->move(1405, 77);
    WID->setFixedSize(90, 900);


    PenColor = new QPushButton(WID);
    PenColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/PEN1.png")));
    PenColor->setIconSize(QSize(50, 50));
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
    PenColor->adjustSize();
    PenColor->move(13, 0);
    PenColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    PenWidth = new QSlider(Qt::Horizontal, WID);
    PenWidth->move(2, 70);
    PenWidth->setStyleSheet("color: rgb(160, 200, 180);\n");
    PenWidth->setFixedWidth(85);
    PenWidth->setRange(0, 100);
    PenWidth->setEnabled(true);
    PenWidth->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    PenWidth->setValue(50);
    PenWIDTH=50;

    connect(PenWidth, SIGNAL(sliderMoved(int)), this, SLOT(SetPenWidth(int)));

    LabelPenWIDTH = new QLabel("50", WID);
    LabelPenWIDTH->setFixedWidth(60);
    LabelPenWIDTH->setFixedHeight(20);
    LabelPenWIDTH->move(15, 100);
    LabelPenWIDTH->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelPenWIDTH->setAlignment(Qt::AlignCenter);

    BrushColor = new QPushButton(WID);
    BrushColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(13, 150);
    BrushColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    CDPen = new QColorDialog(WID);
    CDPen->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDPen, SIGNAL(colorSelected(QColor)), this, SLOT(SetPenColor(QColor)));

    CDBrush = new QColorDialog(WID);
    CDBrush->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDBrush, SIGNAL(colorSelected(QColor)), this, SLOT(SetBrushColor(QColor)));

    connect(PenColor, SIGNAL(released()), CDPen, SLOT(show()));
    connect(BrushColor, SIGNAL(released()), CDBrush, SLOT(show()));


    WID->hide();
}

void EllTool::SetUP()
{
    if(!UP)
    {
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        UP = true;
        WID->show();
    }else
    {
        B->setStyleSheet("");
        UP = false;
        WID->hide();
    }
}

void EllTool::SetPenWidth(int w)
{
    PenWIDTH = w;

    if(w==0)
    {
        PenWidth->setStyleSheet("color: rgb(0, 0, 0);\n");
        LabelPenWIDTH->setStyleSheet("color: rgb(255, 0, 0);");
        LabelPenWIDTH->setText("No Pen");
    }
    else
    {
        PenWidth->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelPenWIDTH->setText(QString::number(w));
    }

}

void EllTool::SetPenColor(QColor Q)
{
    PenCOLOR = Q;
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
}
void EllTool::SetBrushColor(QColor Q)
{
    BrushCOLOR = Q;
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
}


void EllTool::Press(qreal x, qreal y, SceneClass *sc)
{
    if(UP)
    {
        QGraphicsEllipseItem*E = new QGraphicsEllipseItem(x, y, 1, 1);

        if(PenWIDTH>0){
            pen.setWidth(PenWIDTH);
            pen.setCapStyle(Qt::RoundCap);
            pen.setColor(PenCOLOR);
            E->setPen(pen);
        }else E->setPen(Qt::NoPen);
        E->setBrush(QBrush(BrushCOLOR));
        sc->addItem(E);

        sc->it->E = E;
        sc->it->type = 2;
        sc->ItemsList->push_back(sc->it);

        draw = true;

   }
}
void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY, SceneClass *sc)
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
