#include "penwidget.h"

PenWidget::~PenWidget()
{
    this->destroy();
}

PenWidget::PenWidget(QMainWindow *parent, int y) : QMainWindow(parent)
{
    PenWIDGET = new QWidget(parent);
    PenWIDGET->move(1405, y);
    PenWIDGET->setFixedSize(90, 450);

    PenColor = new QPushButton(PenWIDGET);
    PenColor->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/PEN1.png")));
    PenColor->setIconSize(QSize(50, 50));
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));
    PenColor->adjustSize();
    PenColor->move(13, 0);
    PenColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    //PEN WIDTH
    TitlePenWIdth = new QLabel("Pen Width:", PenWIDGET);
    TitlePenWIdth->setFixedWidth(80);
    TitlePenWIdth->setFixedHeight(20);
    TitlePenWIdth->move(5, 75);
    TitlePenWIdth->setFont(QFont("Misc Fixed", 8, 5, false));
    TitlePenWIdth->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitlePenWIdth->setAlignment(Qt::AlignCenter);

    PenWidth = new QSlider(Qt::Horizontal, PenWIDGET);
    PenWidth->move(2, 95);
    PenWidth->setStyleSheet("color: rgb(255, 255, 255);\n");
    PenWidth->setFixedWidth(85);
    PenWidth->setRange(0, 100);
    PenWidth->setEnabled(true);
    PenWidth->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    PenWidth->setValue(20);

    connect(PenWidth, SIGNAL(sliderMoved(int)), this, SLOT(SetPenWidth(int)));

    LabelPenWIDTH = new QLabel("20", PenWIDGET);
    LabelPenWIDTH->setFixedWidth(60);
    LabelPenWIDTH->setFixedHeight(20);
    LabelPenWIDTH->move(15, 115);
    LabelPenWIDTH->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelPenWIDTH->setAlignment(Qt::AlignCenter);
    //~PEN WIDTH

    //PEN STYLE
    TitlePenStyle = new QLabel("PenStyle:", PenWIDGET);
    TitlePenStyle->setFixedWidth(80);
    TitlePenStyle->setFixedHeight(20);
    TitlePenStyle->move(5, 140);
    TitlePenStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitlePenStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitlePenStyle->setAlignment(Qt::AlignCenter);

    PenStyleBox = new QComboBox(PenWIDGET);
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
    TitleCapStyle = new QLabel("CapStyle:", PenWIDGET);
    TitleCapStyle->setFixedWidth(80);
    TitleCapStyle->setFixedHeight(20);
    TitleCapStyle->move(5, 200);
    TitleCapStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleCapStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleCapStyle->setAlignment(Qt::AlignCenter);

    CapStyleBox = new QComboBox(PenWIDGET);
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
    TitleJointStyle = new QLabel("JointStyle:", PenWIDGET);
    TitleJointStyle->setFixedWidth(90);
    TitleJointStyle->setFixedHeight(20);
    TitleJointStyle->move(0, 260);
    TitleJointStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleJointStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleJointStyle->setAlignment(Qt::AlignCenter);

    JointStyleBox = new QComboBox(PenWIDGET);
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

    TitleOpacity = new QLabel("Opacity:", PenWIDGET);
    TitleOpacity->setFixedWidth(90);
    TitleOpacity->setFixedHeight(20);
    TitleOpacity->move(0, 320);
    TitleOpacity->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleOpacity->setAlignment(Qt::AlignCenter);

    Opacity = new QSlider(Qt::Horizontal, PenWIDGET);
    Opacity->move(2, 340);
    Opacity->setStyleSheet("color: rgb(255, 255, 255);\n");
    Opacity->setFixedWidth(85);
    Opacity->setRange(0, 100);
    Opacity->setEnabled(true);
    Opacity->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    Opacity->setValue(100);

    connect(Opacity, SIGNAL(sliderMoved(int)), this, SLOT(SetOpacity(int)));

    LabelOpacity = new QLabel("100%", PenWIDGET);
    LabelOpacity->setFixedWidth(90);
    LabelOpacity->setFixedHeight(20);
    LabelOpacity->move(0, 360);
    LabelOpacity->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelOpacity->setAlignment(Qt::AlignCenter);

    //ANGLE
    TitleAngle = new QLabel("Rotate:", PenWIDGET);
    TitleAngle->setFixedWidth(90);
    TitleAngle->setFixedHeight(20);
    TitleAngle->move(0, 385);
    TitleAngle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleAngle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleAngle->setAlignment(Qt::AlignCenter);


    Angle = new QSlider(Qt::Horizontal, PenWIDGET);
    Angle->move(2, 405);
    Angle->setStyleSheet("color: rgb(255, 255, 255);\n");
    Angle->setFixedWidth(85);
    Angle->setRange(0, 45);
    Angle->setEnabled(true);
    Angle->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    Angle->setValue(0);

    connect(Angle, SIGNAL(sliderMoved(int)), this, SLOT(SetAngle(int)));

    LabelAngle = new QLabel("0°", PenWIDGET);
    LabelAngle->setFixedWidth(90);
    LabelAngle->setFixedHeight(20);
    LabelAngle->move(0, 425);
    LabelAngle->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelAngle->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelAngle->setAlignment(Qt::AlignCenter);
    //~ANGLE

    CDPen = new QColorDialog(parent);
    CDPen->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDPen, SIGNAL(colorSelected(QColor)), this, SLOT(SetPenColor(QColor)));
    connect(PenColor, SIGNAL(released()), CDPen, SLOT(show()));
}

QPen PenWidget::ReturnPen()
{
    QPen pen;
    pen.setWidth(PenWIDTH);
    pen.setColor(PenCOLOR);
    pen.setStyle(PenSTYLE);
    pen.setCapStyle(CapSTYLE);
    pen.setJoinStyle(JointSTYLE);

    return pen;
}

void PenWidget::SetPenWidth(int w)
{
    PenWIDTH = w;

    if(w==0)
    {
        LabelPenWIDTH->setStyleSheet("color: rgb(255, 0, 0);");
        LabelPenWIDTH->setText("No Pen");

        TitlePenStyle->hide();
        PenStyleBox->hide();
        TitleCapStyle->hide();
        CapStyleBox->hide();
        TitleJointStyle->hide();
        JointStyleBox->hide();
    }
    else
    {
        LabelPenWIDTH->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelPenWIDTH->setText(QString::number(w));

        TitlePenStyle->show();
        PenStyleBox->show();
        TitleCapStyle->show();
        CapStyleBox->show();
        TitleJointStyle->show();
        JointStyleBox->show();
    }

    emit Changed();

}

void PenWidget::SetPenColor(QColor Q)
{
    PenCOLOR = Q;
    PenColor->setStyleSheet(QString("background-color: %1").arg(PenCOLOR.name()));

    emit Changed();
}

void PenWidget::SetPenStyle(QString s)
{
    if(s=="Solid")PenSTYLE = Qt::SolidLine;
    if(s=="Dash")PenSTYLE = Qt::DashLine;
    if(s=="Dot")PenSTYLE = Qt::DotLine;
    if(s=="DashDot")PenSTYLE = Qt::DashDotLine;
    if(s=="DashDotDot")PenSTYLE = Qt::DashDotDotLine;
    if(s=="CustomDash")PenSTYLE = Qt::CustomDashLine;

    emit Changed();
}

void PenWidget::SetPenCapStyle(QString s)
{
    if(s=="Square")CapSTYLE = Qt::SquareCap;
    if(s=="Flat")CapSTYLE = Qt::FlatCap;
    if(s=="Round")CapSTYLE = Qt::RoundCap;

    emit Changed();
}

void PenWidget::SetPenJointStyle(QString s)
{
    if(s=="Bevel")JointSTYLE = Qt::BevelJoin;
    if(s=="Miter")JointSTYLE = Qt::MiterJoin;
    if(s=="Round")JointSTYLE = Qt::RoundJoin;

    emit Changed();
}


void PenWidget::SetOpacity(int o)
{
    OPACITY = o*0.01;
    if(o==0)
    {
        LabelOpacity->setStyleSheet("color: rgb(255, 0, 0);");
        LabelOpacity->setText("Invisible");
    }
    else
    {
        LabelOpacity->setStyleSheet("color: rgb(160, 200, 180);\n");
        LabelOpacity->setText(QString::number(o)+"%");
    }

    emit Changed();
}

void PenWidget::SetAngle(int a)
{
    ANGLE = a;
    LabelAngle->setText(QString::number(a)+"°");

    emit Changed();
}
