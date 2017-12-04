#include "optionsfornewfile.h"
#include "ui_optionsfornewfile.h"

OptionsForNewFile::OptionsForNewFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsForNewFile)
{

    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));


    ui->setupUi(this);
    QFont allFont("Misc Fixed", 16, QFont::Bold);

    QString style = "color: rgb(160, 200, 180);\n";
    QString style1 = "background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n";

    ui->Cancel->setStyleSheet(style1);
    ui->OK->setStyleSheet(style1);
    ui->Cancel->setFont(allFont);
    ui->OK->setFont(allFont);
    ui->label->setFont(allFont);
    ui->label->setStyleSheet(style);
    ui->label_2->setFont(allFont);
    ui->label_2->setStyleSheet(style);




    connect(ui->OK, SIGNAL(released()), this, SLOT(pressedOK()));
    connect(ui->Cancel, SIGNAL(released()), this, SLOT(pressedCancel()));
    connect(ui->OK, SIGNAL(released()), this, SLOT(EmitNewSignal()));

    connect(ui->Height, SIGNAL(textChanged(QString)), this, SLOT(Limit(QString)));
    connect(ui->Width, SIGNAL(textChanged(QString)), this, SLOT(Limit(QString)));

    QRegExp rx( "^[0-9]*$" );
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->Height->setValidator( validator );
    ui->Width->setValidator( validator );
}

void OptionsForNewFile::Limit(QString)
{
    if(ui->Height->text().length()>4)
    {
        ui->Height->setText(ui->Height->text().left(4));
    }
    if(ui->Width->text().length()>4)
    {
        ui->Width->setText(ui->Width->text().left(4));
    }


}

void OptionsForNewFile::EmitNewSignal()
{
    emit Signal();
}

void OptionsForNewFile::pressedCancel()
{
    this->hide();
}

void OptionsForNewFile::pressedOK()
{
    H = atoi(ui->Height->text().toStdString().c_str());
    W = atoi(ui->Width->text().toStdString().c_str());
    this->hide();
}



OptionsForNewFile::~OptionsForNewFile()
{
    delete ui;
}
