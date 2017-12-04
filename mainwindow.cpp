#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OptionsForm = new OptionsForNewFile();
    OptionsForm->hide();
    scene = new QGraphicsScene;
    ColorDialog = new QColorDialog(this);
    currentColorOfBrush = QColor(255, 255, 255);

    //STYLE
    QFont allFont("Misc Fixed", 16, QFont::Bold);
    QFont fFont("Misc Fixed", 12, QFont::Bold);
    QString style = "color: rgb(160, 200, 180);\n";
    QString style1 = "background-color: rgb(35, 38, 49);color: rgb(160, 200, 180);\n";

    ui->menuBar->setFont(allFont);
    ui->menuBar->setStyleSheet(style1);
    ui->menuFile->setFont(fFont);
    ui->menuEdit->setFont(fFont);
    ui->NameOfFile->setFont(fFont);
    ui->NameOfFile->setAlignment(Qt::AlignCenter);
    ui->NameOfFile->setStyleSheet(style);

    ui->label->setFont(fFont);
    ui->label->setStyleSheet(style);
    ui->label->setAlignment(Qt::AlignCenter);


    ui->SetColorButton->setFont(fFont);
    ui->SetColorButton->setStyleSheet(style1);


    //STYLE



    //COLOR
    connect(ui->SetColorButton, SIGNAL(released()), this, SLOT(SetColorView()));

    setColor = new QAction(this);
    setColor->setShortcut(tr("Ctrl+P"));
    connect(setColor, SIGNAL(triggered(bool)), this, SLOT(SetColorView()));
    ui->SetColorButton->addAction(setColor);
    //COLOR


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
    ui->menuBar->addAction(openFile);

    connect(ui->menuFile->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));
    //OPEN FILE

    //NEW FILE
    newFile = new QAction(this);
    newFile->setShortcut(tr("Ctrl+N"));
    connect(newFile, SIGNAL(triggered(bool)), this, SLOT(FileNew(bool)));
    ui->menuBar->addAction(newFile);

    connect(ui->menuFile->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(FileNew(bool)));
    //NEW FILE

    //CLOSE FILE
    connect(ui->menuFile->actions().at(4), SIGNAL(triggered(bool)), this, SLOT(FileClose(bool)));

    //SAVE AS FILE
    saveFileAs = new QAction(this);
    saveFileAs->setShortcut(tr("Ctrl+Shift+S"));
    connect(saveFileAs, SIGNAL(triggered(bool)), this, SLOT(FileSaveAs(bool)));
    ui->menuBar->addAction(saveFileAs);

    connect(ui->menuFile->actions().at(3), SIGNAL(triggered(bool)), this, SLOT(FileSaveAs(bool)));
    //SAVE AS FILE


    //------



}


void MainWindow::SetColorView()
{    
    currentColorOfBrush = ColorDialog->getColor();
    ui->Color->setStyleSheet(QString("background: %1").arg(currentColorOfBrush.name()));
}

void MainWindow::zoomUpEvent(bool)
{
    if(CountOfZoom<30){
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    ui->graphicsView-> scale(scaleFactor, scaleFactor);
    CountOfZoom++;
    }
}

void MainWindow::zoomDownEvent(bool)
{
    if(CountOfZoom>(-30)){
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    CountOfZoom--;
    }
}

void MainWindow::FileOpen(bool)
{

    fileNameToOpen = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/kor", tr("Image Files (*.png *.jpg *.bmp *.svg)"));

    scene->addPixmap(QPixmap(fileNameToOpen));    
    ui->graphicsView->setScene(scene);
    ui->NameOfFile->setText(fileNameToOpen);
}

void MainWindow::FileNew(bool)
{
    OptionsForm->show();

    connect(OptionsForm, SIGNAL(Signal()), this, SLOT(MakeNewFile()));




}

void MainWindow::MakeNewFile()
{
    X = OptionsForm->W;
    Y = OptionsForm->H;
    if(X>0 && Y>0){

    QPixmap tmppixmap = QPixmap(X, Y);
    tmppixmap.fill(QColor(255,255,255));
    scene->addPixmap(tmppixmap);

    ui->graphicsView->setScene(scene);
    ui->NameOfFile->setText("New_file");
    }

}

void MainWindow::FileClose(bool)
{


}

void MainWindow::FileSaveAs(bool)
{

        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
            "/home/kor", tr("SVG files (*.svg)"));

        if (newPath.isEmpty())
            return;



        QSvgGenerator generator;
        generator.setFileName(newPath);
        generator.setSize(QSize(scene->width(), scene->height()));
        generator.setViewBox(QRect(0, 0, scene->width(), scene->height()));
        generator.setTitle(trUtf8("Name"));
        generator.setDescription(trUtf8("File SVG"));


        QPainter painter;
        painter.begin(&generator);
        scene->render(&painter);
        painter.end();


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
