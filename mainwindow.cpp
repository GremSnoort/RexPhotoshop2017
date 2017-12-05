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


    ui->widget_Zoom->hide();
    QIcon IcZoom = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/file1339191946.png"));
    ui->pushButton_Zoom->setIcon(IcZoom);
    ui->pushButton_Zoom->setIconSize(QSize(40, 40));

    QIcon IcRZoom = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/w256h2561339196101ZoomIn256x256.png"));
    ui->radioButtonZoom->setIcon(IcRZoom);
    ui->radioButtonZoom->setIconSize(QSize(30, 30));

    QIcon IcFill = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/w256h2561348757719Paint.png"));
    ui->pushButton_FillAll->setIcon(IcFill);
    ui->pushButton_FillAll->setIconSize(QSize(40, 40));


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
    ui->NameOfFile->setStyleSheet(style1);

    ui->label->setFont(fFont);
    ui->label->setStyleSheet(style);
    ui->label->setAlignment(Qt::AlignCenter);


    ui->SetColorButton->setFont(fFont);
    ui->SetColorButton->setStyleSheet(style1);

    ui->Tools->setStyleSheet(style);
    ui->Tools->setFont(fFont);

    ui->pushButtonZoom_ActualPixels->setFont(fFont);
    ui->pushButtonZoom_ActualPixels->setStyleSheet(style1);
    ui->pushButtonZoom_FitScreen->setFont(fFont);
    ui->pushButtonZoom_FitScreen->setStyleSheet(style1);

    //STYLE

    //BUTTONS



    connect(ui->pushButton_Zoom, SIGNAL(released()), ui->widget_Zoom, SLOT(show()));



    //BUTTONS

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

    connect(ui->pushButtonZoom_ActualPixels, SIGNAL(released()), this, SLOT(ActualPixelsPressed()));
    connect(ui->pushButtonZoom_FitScreen, SIGNAL(released()), this, SLOT(FitScreenPressed()));
    //ZOOM

    //OPEN FILE
 /*   openFile = new QAction(this);
    openFile->setShortcut(tr("Ctrl+O"));
    connect(openFile, SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));
    ui->menuBar->addAction(openFile);

    connect(ui->menuFile->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));*/
    //OPEN FILE

    //NEW FILE
    newFile = new QAction(this);
    newFile->setShortcut(tr("Ctrl+N"));
    connect(newFile, SIGNAL(triggered(bool)), this, SLOT(FileNew(bool)));
    ui->menuBar->addAction(newFile);

    connect(ui->menuFile->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(FileNew(bool)));
    //NEW FILE

    //CLOSE FILE
    closeFile = new QAction(this);
    closeFile->setShortcut(tr("Ctrl+X"));
    connect(closeFile, SIGNAL(triggered(bool)), this, SLOT(FileClose(bool)));
    ui->menuBar->addAction(closeFile);

    connect(ui->menuFile->actions().at(4), SIGNAL(triggered(bool)), this, SLOT(FileClose(bool)));
    //CLOSE FILE

    //SAVE AS FILE
    saveFileAs = new QAction(this);
    saveFileAs->setShortcut(tr("Ctrl+Shift+S"));
    connect(saveFileAs, SIGNAL(triggered(bool)), this, SLOT(FileSaveAs(bool)));
    ui->menuBar->addAction(saveFileAs);

    connect(ui->menuFile->actions().at(3), SIGNAL(triggered(bool)), this, SLOT(FileSaveAs(bool)));
    //SAVE AS FILE


    //SAVE
    saveFile = new QAction(this);
    saveFile->setShortcut(tr("Ctrl+S"));
    connect(saveFile, SIGNAL(triggered(bool)), this, SLOT(FileSave(bool)));
    ui->menuBar->addAction(saveFile);

    connect(ui->menuFile->actions().at(2), SIGNAL(triggered(bool)), this, SLOT(FileSave(bool)));
    //SAVE

    //------



}

void MainWindow::MakeFill()
{
    if(!ui->NameOfFile->text().isEmpty())
    {
        //scene->
    }
}


void MainWindow::SetColorView()
{    
    currentColorOfBrush = ColorDialog->getColor();
    ui->Color->setStyleSheet(QString("background: %1").arg(currentColorOfBrush.name()));
}


//ZOOM
void MainWindow::zoomUpEvent(bool)
{
    if(CountOfZoom<30){
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.07;
    ui->graphicsView-> scale(scaleFactor, scaleFactor);
    CountOfZoom++;
    }
}

void MainWindow::zoomDownEvent(bool)
{
    if(CountOfZoom>(-30)){
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.07;
    ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    CountOfZoom--;
    }
}

void MainWindow::ActualPixelsPressed()
{
    ui->pushButtonZoom_ActualPixels->setChecked(false);
    if(CountOfZoom>0)
    {
        ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scaleFactor = 1.07;
        for(int i=0; i<abs(CountOfZoom); i++)
        {
            ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
        CountOfZoom=0;
    }
    else if(CountOfZoom<0)
    {
        ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scaleFactor = 1.07;
        for(int i=0; i<abs(CountOfZoom); i++)
        {
            ui->graphicsView-> scale(scaleFactor, scaleFactor);
        }
        CountOfZoom=0;
    }


}

void MainWindow::FitScreenPressed()
{
    ActualPixelsPressed();
    double scaleFactor = 1.07;
    if(scene->height()>=scene->width())
    {
        double Z = scene->height();
        if(scene->height()>=ui->graphicsView->size().height()) //8888888
        {
            while(Z>ui->graphicsView->size().height())
            {
                    Z/=scaleFactor;
                    CountOfZoom--;
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
            }
        }else//scene->height()<ui->graphicsView->size().height()
        {
            while(true)
            {
                    Z*=scaleFactor;
                    CountOfZoom++;
                    if(Z>=ui->graphicsView->size().height())
                    {
                        Z/=scaleFactor;
                        CountOfZoom--;
                        break;
                    }
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                ui->graphicsView->scale(scaleFactor,  scaleFactor);
            }
        }
    }
    else
    {

        double Z = scene->width();

        if(scene->width()>ui->graphicsView->size().width()) //8888888
        {
            while(Z>ui->graphicsView->size().width())
            {
                    Z/=scaleFactor;
                    CountOfZoom--;
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
            }
        }else//scene->height()<ui->graphicsView->size().height()
        {
            while(true)
            {
                    Z*=scaleFactor;
                    CountOfZoom++;
                    if(Z>=ui->graphicsView->size().width())
                    {
                        Z/=scaleFactor;
                        CountOfZoom--;
                        break;
                    }
            }
            for(int i=0; i<abs(CountOfZoom); i++)
            {
                ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
                ui->graphicsView->scale(scaleFactor,  scaleFactor);
            }
        }

    }
}

//ZOOM
///https://evileg.com/ru/post/149/
/*void MainWindow::FileOpen(bool)//https://stackoverflow.com/questions/34183996/saving-a-qgraphicsscene-to-svg-changes-scaling
{

    QString fileNameToOpen = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/kor", tr("Image Files (*.jpg *.svg)"));

    scene->addPixmap(QPixmap(fileNameToOpen));

    ui->graphicsView->setScene(scene);

    ui->NameOfFile->setText(fileNameToOpen);

}*/

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
        if(!ui->NameOfFile->text().isEmpty())FileClose(true);


        QPixmap tmppixmap = QPixmap(X, Y);
        tmppixmap.fill(QColor(255,255,255));
        scene=new QGraphicsScene;
        scene->addPixmap(tmppixmap);

        ui->graphicsView->setScene(scene);
        ui->NameOfFile->setText("New_file");

    }

}

void MainWindow::FileClose(bool)
{
    if(!IsModified)
    {

        scene->clear();
        ui->graphicsView->setScene(scene);
        ui->NameOfFile->clear();
    }else FileSaveAs(true);

}

void MainWindow::FileSaveAs(bool)
{
    if(!ui->NameOfFile->text().isEmpty()){
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
}

void MainWindow::FileSave(bool)
{
    if(!ui->NameOfFile->text().isEmpty()){

        QString newPath = ui->NameOfFile->text();
        if(newPath=="New_file" || newPath.contains(".jpg")) FileSaveAs(true);
        else{

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
    }
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
