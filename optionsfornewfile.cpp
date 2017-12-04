#include "optionsfornewfile.h"
#include "ui_optionsfornewfile.h"

OptionsForNewFile::OptionsForNewFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsForNewFile)
{
    ui->setupUi(this);


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
