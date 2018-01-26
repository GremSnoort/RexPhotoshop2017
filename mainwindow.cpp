#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roundcornerswidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ///GraphicsView
    myWorkSpace = new GraphicsViewClass();
    ui->gridLayout->addWidget(myWorkSpace);
    myWorkSpace->setCursor(QCursor(Qt::CrossCursor));

    ///form for correct save
    AskSaveDialog = new AskForSave(this);
    AskSaveDialog->hide();
    connect(AskSaveDialog, SIGNAL(Save(bool)), this, SLOT(FileSave(bool)));
    connect(AskSaveDialog, SIGNAL(SaveAs(bool)), this, SLOT(FileSaveAs(bool)));


    //ZOOM
    zoomUp = new QAction(this);
    zoomUp->setShortcut(tr("Ctrl+Up"));
    myWorkSpace->addAction(zoomUp);

    zoomDown = new QAction(this);
    zoomDown->setShortcut(tr("Ctrl+Down"));
    myWorkSpace->addAction(zoomDown);

    connect(zoomUp, SIGNAL(triggered(bool)), myWorkSpace, SLOT(zoomUpEvent(bool)));
    connect(zoomDown, SIGNAL(triggered(bool)), myWorkSpace, SLOT(zoomDownEvent(bool)));


    ///Line for the File Name
    ui->NameOfFile->setReadOnly(true);
    ui->NameOfFile->setText("New_File");
    ui->NameOfFile->setAlignment(Qt::AlignCenter);


    ///BUTTONS STYLE
    ui->pushButton_Zoom->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/file1339191946.png")));
    ui->pushButton_Zoom->setIconSize(QSize(40, 40));

    ui->pushButton_Fill->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/w256h2561348757719Paint.png")));
    ui->pushButton_Fill->setIconSize(QSize(40, 40));    





    ///MENU BAR -> MENU FILE
    //NEW
    ui->menuFile->actions().at(0)->setShortcut(tr("Ctrl+N"));
    ui->menuFile->actions().at(0)->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/newfileicon.png")));
    connect(ui->menuFile->actions().at(0), SIGNAL(triggered(bool)), this, SLOT(FileNew(bool)));

    //OPEN
    ui->menuFile->actions().at(1)->setShortcut(tr("Ctrl+O"));
    ui->menuFile->actions().at(1)->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/open-file-icon.png")));
    connect(ui->menuFile->actions().at(1), SIGNAL(triggered(bool)), this, SLOT(FileOpen(bool)));

    //SAVE
    ui->menuFile->actions().at(2)->setShortcut(tr("Ctrl+S"));
    ui->menuFile->actions().at(2)->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Saveicon.png")));
    connect(ui->menuFile->actions().at(2), SIGNAL(triggered(bool)), this, SLOT(FileSave(bool)));

    //SAVE AS
    ui->menuFile->actions().at(3)->setShortcut(tr("Ctrl+Shift+S"));
    ui->menuFile->actions().at(3)->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Save-as-icon.png")));
    connect(ui->menuFile->actions().at(3), SIGNAL(triggered(bool)), this, SLOT(FileSaveAs(bool)));

    //CLOSE
    ui->menuFile->actions().at(4)->setShortcut(tr("Ctrl+X"));
    ui->menuFile->actions().at(4)->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/closefileicon.png")));
    connect(ui->menuFile->actions().at(4), SIGNAL(triggered(bool)), this, SLOT(FileClose(bool)));

    ItemBaseClass::PWID = new PenWidget(this, 75);
    ItemBaseClass::BWID = new BrushWidget(this, 655);
    ItemBaseClass::RWID = new RoundCornersWidget(this, 525);

    ItemBaseClass::PWID->PenWIDGET->hide();
    ItemBaseClass::BWID->BrushWIDGET->hide();
    ItemBaseClass::RWID->RoundWIDGET->hide();

    ToolRegistrator::registry.append(RectTool::RTReg.makeTool(this, myWorkSpace->scene, 75));
    ToolRegistrator::registry.append(EllTool::ETReg.makeTool(this, myWorkSpace->scene, 145));
    ToolRegistrator::registry.append(RoundRectTool::RRTReg.makeTool(this, myWorkSpace->scene, 215));
    ToolRegistrator::registry.append(SelectionTool::STReg.makeTool(this, myWorkSpace->scene, 355));
}

void MainWindow::open()
{

    QString fileNameToOpen = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/kor", tr("Image Files (*.jpg *.svg)"));

    if (fileNameToOpen.isEmpty())
        return;




    myWorkSpace->CreateNew();
    //myWorkSpace->SetColor(currentColorOfBrush);






    foreach (QGraphicsRectItem *item, SVGOpen::getRectElements(fileNameToOpen))
    {
        QGraphicsRectItem *rect = item;
        myWorkSpace->scene->addItem(rect);

        myWorkSpace->scene->items().first()->setFlag(QGraphicsItem::ItemIsSelectable, true);
        myWorkSpace->scene->items().first()->setFlag(QGraphicsItem::ItemIsMovable, true);



    }

    foreach (QGraphicsEllipseItem *item, SVGOpen::getEllipseElements(fileNameToOpen))
    {
        QGraphicsEllipseItem *ell = item;
        myWorkSpace->scene->addItem(ell);

        myWorkSpace->scene->items().first()->setFlag(QGraphicsItem::ItemIsSelectable, true);
        myWorkSpace->scene->items().first()->setFlag(QGraphicsItem::ItemIsMovable, true);



    }



    ui->NameOfFile->setText(fileNameToOpen);



}


void MainWindow::FileOpen(bool)
{
    if(myWorkSpace->scene->IsModified==true)
    {
        AskSaveDialog->show();
        connect(AskSaveDialog, SIGNAL(Cancel()), this, SLOT(open()));
        MODE="open";

    }else open();

}

void MainWindow::newone()
{

    MakeNewFile();
}

void MainWindow::FileNew(bool)
{
    if(myWorkSpace->scene->IsModified==true)
    {
        AskSaveDialog->show();
        connect(AskSaveDialog, SIGNAL(Cancel()), this, SLOT(newone()));
        MODE="new";

    }else newone();

}

void MainWindow::MakeNewFile()
{



        if(!ui->NameOfFile->text().isEmpty())FileClose(true);
        myWorkSpace->CreateNew();
        //myWorkSpace->SetColor(currentColorOfBrush);
        ui->NameOfFile->setText("New_file");







}

void MainWindow::close()
{


    myWorkSpace->scene->clear();
    myWorkSpace->scene->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    myWorkSpace->scene->setSceneRect(0, 0, 1315, 895);
    myWorkSpace->scene->IsModified=false;
    ui->NameOfFile->setText("New_File");





}

void MainWindow::FileClose(bool)
{
    if(myWorkSpace->scene->IsModified==true)
    {
        AskSaveDialog->show();
        connect(AskSaveDialog, SIGNAL(Cancel()), this, SLOT(close()));
        MODE="close";

    }else close();

}

void MainWindow::FileSaveAs(bool)
{
    if(!ui->NameOfFile->text().isEmpty()){
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
            "/home/kor", tr("SVG files (*.svg)"));

        if (newPath.isEmpty())
            return;

myWorkSpace->scene->clearSelection();

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

        ui->NameOfFile->setText(newPath);

        myWorkSpace->scene->IsModified=false;
        if(MODE=="open")open();
        if(MODE=="close")close();
        if(MODE=="new")newone();

        MODE="";

    }
}

void MainWindow::FileSave(bool)
{
    if(!ui->NameOfFile->text().isEmpty()){

        QString newPath = ui->NameOfFile->text();
        if(newPath=="New_file" || newPath.contains(".jpg")) FileSaveAs(true);
        else{
myWorkSpace->scene->clearSelection();
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

            myWorkSpace->scene->IsModified=false;
            if(MODE=="open")open();
            if(MODE=="close")close();
            if(MODE=="new")newone();

            MODE="";
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    //WID->deleteLater();
}
