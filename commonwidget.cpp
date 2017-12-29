#include "commonwidget.h"

CommonWidget::CommonWidget(QMainWindow *parent) : QMainWindow(parent)
{
    WID = new QWidget(parent);
    WID->move(1405, 77);
    WID->setFixedSize(90, 500);

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
    PenWidth->setValue(20);


    connect(PenWidth, SIGNAL(sliderMoved(int)), this, SLOT(SetPenWidth(int)));

    LabelPenWIDTH = new QLabel("20", WID);
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

    Opacity = new QSlider(Qt::Horizontal, WID);
    Opacity->move(2, 220);
    Opacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    Opacity->setFixedWidth(85);
    Opacity->setRange(0, 100);
    Opacity->setEnabled(true);
    Opacity->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    Opacity->setValue(100);


    connect(Opacity, SIGNAL(sliderMoved(int)), this, SLOT(SetOpacity(int)));

    LabelOpacity = new QLabel("100", WID);
    LabelOpacity->setFixedWidth(60);
    LabelOpacity->setFixedHeight(20);
    LabelOpacity->move(15, 250);
    LabelOpacity->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelOpacity->setAlignment(Qt::AlignCenter);

    CDPen = new QColorDialog(parent);
    CDPen->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDPen, SIGNAL(colorSelected(QColor)), this, SLOT(SetPenColor(QColor)));

    CDBrush = new QColorDialog(parent);
    CDBrush->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDBrush, SIGNAL(colorSelected(QColor)), this, SLOT(SetBrushColor(QColor)));

    connect(PenColor, SIGNAL(released()), CDPen, SLOT(show()));
    connect(BrushColor, SIGNAL(released()), CDBrush, SLOT(show()));







}

void CommonWidget::SetOpacity(int o)
{
    OPACITY = o*0.01;
    QTextStream out(stdout);
    out<<OPACITY;
    if(o==0)
    {
        Opacity->setStyleSheet("color: rgb(0, 0, 0);\n");
        LabelOpacity->setStyleSheet("color: rgb(255, 0, 0);");
        LabelOpacity->setText("Invisible");
    }
    else
    {
        Opacity->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelOpacity->setText(QString::number(OPACITY));
    }
}

void CommonWidget::SetPenWidth(int w)
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

void CommonWidget::SetPenColor(QColor Q)
{
    PenCOLOR = Q;
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
}
void CommonWidget::SetBrushColor(QColor Q)
{
    BrushCOLOR = Q;
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
}

CommonWidget::~CommonWidget()
{
    this->close();

    //this->deleteLater();
}
