#include "askforsave.h"
#include "ui_askforsave.h"

AskForSave::AskForSave(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::AskForSave)
{

    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));
    ui->setupUi(this);
    QFont allFont("Misc Fixed", 16, QFont::Bold);
    QFont fFont("Misc Fixed", 12, QFont::Bold);
    QString style = "color: rgb(160, 200, 180);\n";
    QString style1 = "background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n";

    ui->SAVE->setStyleSheet(style1);
    ui->SAVE_AS->setStyleSheet(style1);
    ui->label->setStyleSheet(style);
    ui->label->setFont(fFont);
    ui->SAVE->setFont(allFont);
    ui->SAVE_AS->setFont(allFont);
    ui->label->setAlignment(Qt::AlignCenter);

    connect(ui->SAVE, SIGNAL(released()), this, SLOT(MakeSave()));
    connect(ui->SAVE_AS, SIGNAL(released()), this, SLOT(MakeSaveAs()));
}

void AskForSave::MakeSave()
{
    this->hide();
    emit Save(true);
}

void AskForSave::MakeSaveAs()
{
    this->hide();
    emit SaveAs(true);
}

AskForSave::~AskForSave()
{
    delete ui;
}
