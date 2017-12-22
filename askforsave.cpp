#include "askforsave.h"
#include "ui_askforsave.h"

AskForSave::AskForSave(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::AskForSave)
{

    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));
    ui->setupUi(this);

    ui->buttonBox->addButton(QDialogButtonBox::Save);


    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(MakeSignal(QAbstractButton*)));

}

void AskForSave::MakeSignal(QAbstractButton* b)
{
    this->hide();
    if(b==ui->buttonBox->buttons().at(0))emit SaveAs(true);
    else if(b==ui->buttonBox->buttons().at(2))emit Save(true);
    else if(b==ui->buttonBox->buttons().at(1))emit Cancel();
}

AskForSave::~AskForSave()
{
    delete ui;
}
