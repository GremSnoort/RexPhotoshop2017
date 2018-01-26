#include "roundcornerswidget.h"

RoundCornersWidget::~RoundCornersWidget()
{
    this->destroy();
}

RoundCornersWidget::RoundCornersWidget(QMainWindow *parent, int y) : QMainWindow()
{
    RoundWIDGET = new QWidget(parent);
    RoundWIDGET->move(1405, y);
    RoundWIDGET->setFixedSize(90, 130);

    TitleRoundCornersX = new QLabel("Round_X:", RoundWIDGET);
    TitleRoundCornersX->setFixedWidth(90);
    TitleRoundCornersX->setFixedHeight(20);
    TitleRoundCornersX->move(0, 0);
    TitleRoundCornersX->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleRoundCornersX->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleRoundCornersX->setAlignment(Qt::AlignCenter);

    RoundCornersX = new QSlider(Qt::Horizontal, RoundWIDGET);
    RoundCornersX->move(2, 20);
    RoundCornersX->setStyleSheet("color: rgb(255, 255, 255);\n");
    RoundCornersX->setFixedWidth(85);
    RoundCornersX->setRange(0, 100);
    RoundCornersX->setEnabled(true);
    RoundCornersX->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    RoundCornersX->setValue(25);

    connect(RoundCornersX, SIGNAL(sliderMoved(int)), this, SLOT(SetRoundCornersX(int)));

    LabelRoundCornersX = new QLabel("25%", RoundWIDGET);
    LabelRoundCornersX->setFixedWidth(90);
    LabelRoundCornersX->setFixedHeight(20);
    LabelRoundCornersX->move(0, 40);
    LabelRoundCornersX->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelRoundCornersX->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelRoundCornersX->setAlignment(Qt::AlignCenter);

    ///_______________________________________________________________________________________

    TitleRoundCornersY = new QLabel("Round_Y:", RoundWIDGET);
    TitleRoundCornersY->setFixedWidth(90);
    TitleRoundCornersY->setFixedHeight(20);
    TitleRoundCornersY->move(0, 65);
    TitleRoundCornersY->setFont(QFont("Misc Fixed", 8, 5, false));
    TitleRoundCornersY->setStyleSheet("color: rgb(160, 200, 180);\n");
    TitleRoundCornersY->setAlignment(Qt::AlignCenter);

    RoundCornersY = new QSlider(Qt::Horizontal, RoundWIDGET);
    RoundCornersY->move(2, 85);
    RoundCornersY->setStyleSheet("color: rgb(255, 255, 255);\n");
    RoundCornersY->setFixedWidth(85);
    RoundCornersY->setRange(0, 100);
    RoundCornersY->setEnabled(true);
    RoundCornersY->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    RoundCornersY->setValue(25);

    connect(RoundCornersY, SIGNAL(sliderMoved(int)), this, SLOT(SetRoundCornersY(int)));

    LabelRoundCornersY = new QLabel("25%", RoundWIDGET);
    LabelRoundCornersY->setFixedWidth(90);
    LabelRoundCornersY->setFixedHeight(20);
    LabelRoundCornersY->move(0, 105);
    LabelRoundCornersY->setFont(QFont("Misc Fixed", 15, 5, false));
    LabelRoundCornersY->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelRoundCornersY->setAlignment(Qt::AlignCenter);
}

void RoundCornersWidget::SetRoundCornersX(int r)
{
    ROUNDCornersX = r;
    LabelRoundCornersX->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelRoundCornersX->setText(QString::number(r)+"%");

    emit Changed();
}

void RoundCornersWidget::SetRoundCornersY(int r)
{
    ROUNDCornersY = r;
    LabelRoundCornersY->setStyleSheet("color: rgb(160, 200, 180);\n");
    LabelRoundCornersY->setText(QString::number(r)+"%");

    emit Changed();
}

