#include "brushwidget.h"

BrushWidget::~BrushWidget()
{
    this->destroy();
}

BrushWidget::BrushWidget(QMainWindow *parent, int y) : QMainWindow(parent)
{
    BrushWIDGET = new QWidget(parent);
    BrushWIDGET->move(1405, y);
    BrushWIDGET->setFixedSize(90, 300);

    BrushColor = new QPushButton(BrushWIDGET);
    BrushColor->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Colorpalette256.png")));
    BrushColor->setIconSize(QSize(50, 50));
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));
    BrushColor->adjustSize();
    BrushColor->move(13, 0);
    BrushColor->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    //BRUSH STYLE
    TitleBrushStyle = new QLabel("BrushStyle:", BrushWIDGET);
    TitleBrushStyle->setFixedWidth(90);
    TitleBrushStyle->setFixedHeight(20);
    TitleBrushStyle->move(0, 75);
    TitleBrushStyle->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleBrushStyle->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleBrushStyle->setAlignment(Qt::AlignCenter);

    BrushStyleBox = new QComboBox(BrushWIDGET);
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
    BrushStyleBox->move(0, 100);

    connect(BrushStyleBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(SetBrushStyle(QString)));
    //~BRUSH STYLE

    CDBrush = new QColorDialog(parent);
    CDBrush->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");
    connect(CDBrush, SIGNAL(colorSelected(QColor)), this, SLOT(SetBrushColor(QColor)));
    connect(BrushColor, SIGNAL(released()), CDBrush, SLOT(show()));
}

QBrush BrushWidget::ReturnBrush()
{
    QBrush br;
    br.setColor(BrushCOLOR);
    br.setStyle(BrushSTYLE);

    return br;
}

void BrushWidget::SetBrushStyle(QString s)
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

    emit Changed();
}

void BrushWidget::SetBrushColor(QColor Q)
{
    BrushCOLOR = Q;
    BrushColor->setStyleSheet(QString("background-color: %1").arg(BrushCOLOR.name()));

    emit Changed();
}
