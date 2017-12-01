#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //STYLE
    QFont allFont("Misc Fixed", 16, QFont::Bold);
    QFont fFont("Misc Fixed", 12, QFont::Bold);
    QString style = "color: rgb(160, 170, 180);\n";
    ui->menuBar->setFont(allFont);
    ui->menuFile->setFont(fFont);
    ui->menuEdit->setFont(fFont);
    ui->NameOfFile->setFont(fFont);
    ui->NameOfFile->setAlignment(Qt::AlignCenter);
    ui->NameOfFile->setStyleSheet(style);
    ui->menuBar->setStyleSheet(style);
    //STYLE


    scene = new QGraphicsScene;

    //ZOOM
    zoomUp = new QAction(this);
    zoomDown = new QAction(this);

    zoomUp->setShortcut(tr("Ctrl+Up"));
    zoomDown->setShortcut(tr("Ctrl+Down"));

    connect(zoomUp, SIGNAL(triggered(bool)), this, SLOT(zoomUpEvent(bool)));
    connect(zoomDown, SIGNAL(triggered(bool)), this, SLOT(zoomDownEvent(bool)));

    ui->graphicsView->addAction(zoomUp);
    ui->graphicsView->addAction(zoomDown);
    //ZOOM

    //OPEN FILE
    openFile = new QAction(this);
    openFile->setShortcut(tr("Ctrl+O"));
    connect(openFile, SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));
    ui->graphicsView->addAction(openFile);

    connect(ui->menuFile->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));
    //OPEN FILE

}

void MainWindow::zoomUpEvent(bool)
{
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    ui->graphicsView-> scale(scaleFactor, scaleFactor);
    QTextStream out(stdout);

}

void MainWindow::zoomDownEvent(bool)
{
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
}

void MainWindow::FileOpen(bool)
{

    fileNameToOpen = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/kor", tr("Image Files (*.png *.jpg *.bmp *.svg)"));

    scene->addPixmap(QPixmap(fileNameToOpen));    
    ui->graphicsView->setScene(scene);
    ui->NameOfFile->setText(fileNameToOpen);
}

///ZOOM IN MOUSE. BUT IT WORKS BAD WITH SCROLL
/*
void MainWindow::wheelEvent(QWheelEvent *event){

        ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);


        // Scale the view / do the zoom
        double scaleFactor = 1.15;
        if(event->delta()>0 ) {
            // Zoom in
            ui->graphicsView-> scale(scaleFactor, scaleFactor);
        } else {
            // Zooming out
             ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
}*/


MainWindow::~MainWindow()
{
    delete ui;
}
