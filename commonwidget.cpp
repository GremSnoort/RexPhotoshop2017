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


    //PEN WIDTH
    TitlePenWIdth = new QLabel("Pen Width:", WID);
    TitlePenWIdth->setFixedWidth(80);
    TitlePenWIdth->setFixedHeight(20);
    TitlePenWIdth->move(5, 80);
    TitlePenWIdth->setFont(QFont("Misc Fixed", 8, 5, false));
    TitlePenWIdth->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitlePenWIdth->setAlignment(Qt::AlignCenter);



    PenWidth = new QSlider(Qt::Horizontal, WID);
    PenWidth->move(2, 100);
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
    LabelPenWIDTH->move(15, 120);
    LabelPenWIDTH->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelPenWIDTH->setAlignment(Qt::AlignCenter);
    //~PEN WIDTH


    //PEN STYLE
    TitlePenStyle = new QLabel("PenStyle:", WID);
    TitlePenStyle->setFixedWidth(80);
    TitlePenStyle->setFixedHeight(20);
    TitlePenStyle->move(5, 145);
    TitlePenStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitlePenStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitlePenStyle->setAlignment(Qt::AlignCenter);

    PenStyleBox = new QComboBox(WID);
    PenStyleBox->setFocusPolicy(Qt::NoFocus);

    PenStyleBox->addItem("Solid");
    PenStyleBox->addItem("Dash");
    PenStyleBox->addItem("Dot");
    PenStyleBox->addItem("DashDot");
    PenStyleBox->addItem("DashDotDot");
    PenStyleBox->addItem("CustomDash");

    PenStyleBox->setFont(QFont("Misc Fixed", 8, 5, false));
    PenStyleBox->setStyleSheet("background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n");

    PenStyleBox->setItemData ( 0, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    PenStyleBox->setItemData ( 1, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    PenStyleBox->setItemData ( 2, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    PenStyleBox->setItemData ( 3, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    PenStyleBox->setItemData ( 4, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    PenStyleBox->setItemData ( 5, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );

    PenStyleBox->setItemData ( 0, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    PenStyleBox->setItemData ( 1, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    PenStyleBox->setItemData ( 2, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    PenStyleBox->setItemData ( 3, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    PenStyleBox->setItemData ( 4, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    PenStyleBox->setItemData ( 5, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );



    PenStyleBox->setFixedWidth(90);
    PenStyleBox->setFixedHeight(30);
    PenStyleBox->move(0, 170);
    //~PEN STYLE


    //CAP STYLE
    TitleCapStyle = new QLabel("CapStyle:", WID);
    TitleCapStyle->setFixedWidth(80);
    TitleCapStyle->setFixedHeight(20);
    TitleCapStyle->move(5, 205);
    TitleCapStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleCapStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleCapStyle->setAlignment(Qt::AlignCenter);

    CapStyleBox = new QComboBox(WID);
    CapStyleBox->setFocusPolicy(Qt::NoFocus);

    CapStyleBox->addItem("Square");
    CapStyleBox->addItem("Flat");
    CapStyleBox->addItem("Round");


    CapStyleBox->setFont(QFont("Misc Fixed", 8, 5, false));
    CapStyleBox->setStyleSheet("background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n");

    CapStyleBox->setItemData ( 0, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    CapStyleBox->setItemData ( 1, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    CapStyleBox->setItemData ( 2, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );


    CapStyleBox->setItemData ( 0, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    CapStyleBox->setItemData ( 1, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    CapStyleBox->setItemData ( 2, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );



    CapStyleBox->setFixedWidth(90);
    CapStyleBox->setFixedHeight(30);
    CapStyleBox->move(0, 230);
    //~CAP STYLE

    //JOINT STYLE
    TitleJointStyle = new QLabel("JointStyle:", WID);
    TitleJointStyle->setFixedWidth(90);
    TitleJointStyle->setFixedHeight(20);
    TitleJointStyle->move(0, 265);
    TitleJointStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleJointStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleJointStyle->setAlignment(Qt::AlignCenter);

    JointStyleBox = new QComboBox(WID);
    JointStyleBox->setFocusPolicy(Qt::NoFocus);

    JointStyleBox->addItem("Bevel");
    JointStyleBox->addItem("Miter");
    JointStyleBox->addItem("Round");


    JointStyleBox->setFont(QFont("Misc Fixed", 8, 5, false));
    JointStyleBox->setStyleSheet("background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n");

    JointStyleBox->setItemData ( 0, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    JointStyleBox->setItemData ( 1, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    JointStyleBox->setItemData ( 2, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );


    JointStyleBox->setItemData ( 0, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    JointStyleBox->setItemData ( 1, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    JointStyleBox->setItemData ( 2, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );



    JointStyleBox->setFixedWidth(90);
    JointStyleBox->setFixedHeight(30);
    JointStyleBox->move(0, 290);

    //~JOINT STYLE


    BrushColor = new QPushButton(WID);
    BrushColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(13, 300);
    BrushColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    Opacity = new QSlider(Qt::Horizontal, WID);
    Opacity->move(2, 370);
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
    LabelOpacity->move(15, 400);
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
