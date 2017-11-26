#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont allFont("Misc Fixed", 16, QFont::Bold);
    QFont fFont("Misc Fixed", 12, QFont::Bold);
    QString style = "color: rgb(160, 170, 180);\n";
    ui->menuBar->setFont(allFont);
    ui->menuFile->setFont(fFont);
    ui->menuEdit->setFont(fFont);
    ui->menuBar->setStyleSheet(style);

    scene = new QGraphicsScene;

    connect(ui->menuFile->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));

}


void MainWindow::FileOpen(bool b)
{

    fileNameToOpen = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/kor", tr("Image Files (*.png *.jpg *.bmp *.svg)"));

    scene->addPixmap(QPixmap(fileNameToOpen));
    scene->addText("test");
    ui->graphicsView->setScene(scene);
    QTextStream out(stdout);
    out<<fileNameToOpen;

}




MainWindow::~MainWindow()
{
    delete ui;
}
