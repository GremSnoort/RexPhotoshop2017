#include "commonwidget.h"

CommonWidget::CommonWidget(QMainWindow *parent) : QMainWindow(parent)
{
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


    //PEN WIDTH
    TitlePenWIdth = new QLabel("Pen Width:", WID);
    TitlePenWIdth->setFixedWidth(80);
    TitlePenWIdth->setFixedHeight(20);
    TitlePenWIdth->move(5, 75);
    TitlePenWIdth->setFont(QFont("Misc Fixed", 8, 5, false));
    TitlePenWIdth->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitlePenWIdth->setAlignment(Qt::AlignCenter);



    PenWidth = new QSlider(Qt::Horizontal, WID);
    PenWidth->move(2, 95);
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
    LabelPenWIDTH->move(15, 115);
    LabelPenWIDTH->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelPenWIDTH->setAlignment(Qt::AlignCenter);
    //~PEN WIDTH


    //PEN STYLE
    TitlePenStyle = new QLabel("PenStyle:", WID);
    TitlePenStyle->setFixedWidth(80);
    TitlePenStyle->setFixedHeight(20);
    TitlePenStyle->move(5, 140);
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
    PenStyleBox->move(0, 165);

    connect(PenStyleBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(SetPenStyle(QString)));
    //~PEN STYLE


    //CAP STYLE
    TitleCapStyle = new QLabel("CapStyle:", WID);
    TitleCapStyle->setFixedWidth(80);
    TitleCapStyle->setFixedHeight(20);
    TitleCapStyle->move(5, 200);
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
    CapStyleBox->move(0, 225);

    connect(CapStyleBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(SetPenCapStyle(QString)));
    //~CAP STYLE

    //JOINT STYLE
    TitleJointStyle = new QLabel("JointStyle:", WID);
    TitleJointStyle->setFixedWidth(90);
    TitleJointStyle->setFixedHeight(20);
    TitleJointStyle->move(0, 260);
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
    JointStyleBox->move(0, 285);

    connect(JointStyleBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(SetPenJointStyle(QString)));
    //~JOINT STYLE


    BrushColor = new QPushButton(WID);
    BrushColor->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(13, 330);
    BrushColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);


    TitleOpacity = new QLabel("Opacity:", WID);
    TitleOpacity->setFixedWidth(90);
    TitleOpacity->setFixedHeight(20);
    TitleOpacity->move(0, 405);
    TitleOpacity->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleOpacity->setAlignment(Qt::AlignCenter);


    Opacity = new QSlider(Qt::Horizontal, WID);
    Opacity->move(2, 425);
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
    LabelOpacity->move(15, 445);
    LabelOpacity->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelOpacity->setAlignment(Qt::AlignCenter);



    //BRUSH STYLE
    TitleBrushStyle = new QLabel("BrushStyle:", WID);
    TitleBrushStyle->setFixedWidth(90);
    TitleBrushStyle->setFixedHeight(20);
    TitleBrushStyle->move(0, 470);
    TitleBrushStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleBrushStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleBrushStyle->setAlignment(Qt::AlignCenter);

    BrushStyleBox = new QComboBox(WID);
    BrushStyleBox->setFocusPolicy(Qt::NoFocus);

    BrushStyleBox->addItem("Solid");
    BrushStyleBox->addItem("Dense1");
    BrushStyleBox->addItem("Dense2");
    BrushStyleBox->addItem("Dense3");
    BrushStyleBox->addItem("Dense4");
    BrushStyleBox->addItem("Dense5");
    BrushStyleBox->addItem("Dense6");
    BrushStyleBox->addItem("Dense7");
    BrushStyleBox->addItem("NoBrush");
    BrushStyleBox->addItem("Hor");
    BrushStyleBox->addItem("Ver");
    BrushStyleBox->addItem("Cross");
    BrushStyleBox->addItem("BDiag");
    BrushStyleBox->addItem("FDiag");
    BrushStyleBox->addItem("DCross");


    BrushStyleBox->setFont(QFont("Misc Fixed", 8, 5, false));
    BrushStyleBox->setStyleSheet("background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n");

    BrushStyleBox->setItemData ( 0, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 1, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 2, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 3, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 4, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 5, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 6, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 7, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 8, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 9, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 10, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 11, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 12, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 13, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );
    BrushStyleBox->setItemData ( 14, QVariant(QBrush(QColor(35, 38, 49))), Qt::BackgroundRole );



    BrushStyleBox->setItemData ( 0, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 1, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 2, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 3, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 4, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 5, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 6, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 7, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 8, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 9, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 10, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 11, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 12, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 13, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );
    BrushStyleBox->setItemData ( 14, QVariant(QBrush(QColor(160, 200, 180))), Qt::TextColorRole );




    BrushStyleBox->setFixedWidth(90);
    BrushStyleBox->setFixedHeight(30);
    BrushStyleBox->move(0, 495);

    connect(BrushStyleBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(SetBrushStyle(QString)));
    //~BRUSH STYLE




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

void CommonWidget::SetPenStyle(QString s)
{
    if(s=="Solid")PenSTYLE = Qt::SolidLine;
    if(s=="Dash")PenSTYLE = Qt::DashLine;
    if(s=="Dot")PenSTYLE = Qt::DotLine;
    if(s=="DashDot")PenSTYLE = Qt::DashDotLine;
    if(s=="DashDotDot")PenSTYLE = Qt::DashDotDotLine;
    if(s=="CustomDash")PenSTYLE = Qt::CustomDashLine;
}

void CommonWidget::SetPenCapStyle(QString s)
{
    if(s=="Square")CapSTYLE = Qt::SquareCap;
    if(s=="Flat")CapSTYLE = Qt::FlatCap;
    if(s=="Round")CapSTYLE = Qt::RoundCap;
}

void CommonWidget::SetPenJointStyle(QString s)
{
    if(s=="Bevel")JointSTYLE = Qt::BevelJoin;
    if(s=="Miter")JointSTYLE = Qt::MiterJoin;
    if(s=="Round")JointSTYLE = Qt::RoundJoin;
}

void CommonWidget::SetBrushStyle(QString s)
{
    if(s=="Solid")BrushSTYLE = Qt::SolidPattern;
    if(s=="Dense1")BrushSTYLE = Qt::Dense1Pattern;
    if(s=="Dense2")BrushSTYLE = Qt::Dense2Pattern;
    if(s=="Dense3")BrushSTYLE = Qt::Dense3Pattern;
    if(s=="Dense4")BrushSTYLE = Qt::Dense4Pattern;
    if(s=="Dense5")BrushSTYLE = Qt::Dense5Pattern;
    if(s=="Dense6")BrushSTYLE = Qt::Dense6Pattern;
    if(s=="Dense7")BrushSTYLE = Qt::Dense7Pattern;
    if(s=="NoBrush")BrushSTYLE = Qt::NoBrush;
    if(s=="Hor")BrushSTYLE = Qt::HorPattern;
    if(s=="Ver")BrushSTYLE = Qt::VerPattern;
    if(s=="Cross")BrushSTYLE = Qt::CrossPattern;
    if(s=="BDiag")BrushSTYLE = Qt::BDiagPattern;
    if(s=="FDiag")BrushSTYLE = Qt::FDiagPattern;
    if(s=="DCross")BrushSTYLE = Qt::DiagCrossPattern;

}

QPen CommonWidget::ReturnPen()
{
    QPen pen;
    pen.setWidth(PenWIDTH);
    pen.setColor(PenCOLOR);
    pen.setStyle(PenSTYLE);
    pen.setCapStyle(CapSTYLE);
    pen.setJoinStyle(JointSTYLE);

    return pen;
}

QBrush CommonWidget::ReturnBrush()
{
    QBrush br;
    br.setColor(BrushCOLOR);
    br.setStyle(BrushSTYLE);

    return br;
}

CommonWidget::~CommonWidget()
{
    this->close();    
}
