#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OptionsForm = new OptionsForNewFile();
    OptionsForm->hide();

    myWorkSpace = new GraphicsViewClass();
    ui->gridLayout->addWidget(myWorkSpace);

    ColorDialog = new QColorDialog(this);    
    currentColorOfBrush = QColor(255, 255, 255);


    myWorkSpace->setCursor(QCursor(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/newcursor.png"), -1, -1));



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

    QIcon IcRect = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/SquareAppleV2.png"));
    ui->pushButton_Rect->setIcon(IcRect);
    ui->pushButton_Rect->setIconSize(QSize(50, 50));

    QIcon IcCircle = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/RoundAppleV2.png"));
    ui->pushButton_Circle->setIcon(IcCircle);
    ui->pushButton_Circle->setIconSize(QSize(50, 50));

    QIcon IcColor = QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/Colorpalette256.png"));
    ui->SetColorButton->setIcon(IcColor);
    ui->SetColorButton->setIconSize(QSize(50, 50));


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



    ColorDialog->setStyleSheet("background-color: rgb(15, 18, 29);color: rgb(160, 200, 180);\n");





    ui->Tools->setStyleSheet(style);
    ui->Tools->setFont(fFont);

    ui->pushButtonZoom_ActualPixels->setFont(fFont);
    ui->pushButtonZoom_ActualPixels->setStyleSheet(style1);
    ui->pushButtonZoom_FitScreen->setFont(fFont);
    ui->pushButtonZoom_FitScreen->setStyleSheet(style1);

    ui->gridLayoutWidget->setStyleSheet(style1);

    //STYLE

    ui->NameOfFile->setReadOnly(true);




    //BUTTONS



    connect(ui->pushButton_Zoom, SIGNAL(released()), ui->widget_Zoom, SLOT(show()));
    connect(ui->pushButton_Zoom, SIGNAL(released()), myWorkSpace, SLOT(SetZoomMode()));
    connect(ui->pushButton_Rect, SIGNAL(released()), myWorkSpace, SLOT(SetRectMode()));
    connect(ui->pushButton_Circle, SIGNAL(released()), myWorkSpace, SLOT(SetCircleMode()));

    //BUTTONS

    //COLOR
    connect(ui->SetColorButton, SIGNAL(released()), ColorDialog, SLOT(show()));

    setColor = new QAction(this);
    setColor->setShortcut(tr("Ctrl+P"));
    connect(setColor, SIGNAL(triggered(bool)), ColorDialog, SLOT(show()));
    ui->SetColorButton->addAction(setColor);


    connect(ColorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(ChangeColor(QColor)));
    //COLOR


    //ZOOM
    zoomUp = new QAction(this);
    zoomDown = new QAction(this);

    zoomUp->setShortcut(tr("Ctrl+Up"));
    zoomDown->setShortcut(tr("Ctrl+Down"));

    connect(zoomUp, SIGNAL(triggered(bool)), myWorkSpace, SLOT(zoomUpEvent(bool)));
    connect(zoomDown, SIGNAL(triggered(bool)), myWorkSpace, SLOT(zoomDownEvent(bool)));

    myWorkSpace->addAction(zoomUp);
    myWorkSpace->addAction(zoomDown);

    connect(ui->pushButtonZoom_ActualPixels, SIGNAL(released()), myWorkSpace, SLOT(ActualPixelsPressed()));
    connect(ui->pushButtonZoom_FitScreen, SIGNAL(released()), myWorkSpace, SLOT(FitScreenPressed()));
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


void MainWindow::ChangeColor(QColor q)
{
    currentColorOfBrush = q;
    myWorkSpace->SetColor(q);
    ui->Color->setStyleSheet(QString("background: %1").arg(currentColorOfBrush.name()));

}



//ZOOM



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

    int X = OptionsForm->W;
    int Y = OptionsForm->H;
    if(X>0 && Y>0){
        if(!ui->NameOfFile->text().isEmpty())FileClose(true);
        myWorkSpace->CreateNew(X, Y);
        myWorkSpace->SetColor(currentColorOfBrush);
        ui->NameOfFile->setText("New_file");

    }

}

void MainWindow::FileClose(bool)
{
    if(!IsModified)
    {
        myWorkSpace->scene->clear();
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
        generator.setSize(QSize(myWorkSpace->scene->width(), myWorkSpace->scene->height()));
        generator.setViewBox(QRect(0, 0, myWorkSpace->scene->width(), myWorkSpace->scene->height()));
        generator.setTitle(trUtf8("Name"));
        generator.setDescription(trUtf8("File SVG"));


        QPainter painter;
        painter.begin(&generator);
        myWorkSpace->scene->render(&painter);

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
            generator.setSize(QSize(myWorkSpace->scene->width(), myWorkSpace->scene->height()));
            generator.setViewBox(QRect(0, 0, myWorkSpace->scene->width(), myWorkSpace->scene->height()));
            generator.setTitle(trUtf8("Name"));
            generator.setDescription(trUtf8("File SVG"));


            QPainter painter;
            painter.begin(&generator);
            myWorkSpace->scene->render(&painter);

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
