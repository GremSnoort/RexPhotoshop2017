#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define private public



#include "recttool.h"
#include "elltool.h"
#include "roundrecttool.h"

#include "svgopen.h"
#include "askforsave.h"
#include "sceneclass.h"

#include <QDebug>

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QAction>
#include <QTextStream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QScrollBar>
#include <QtSvg/QGraphicsSvgItem>
#include <QtSvg/QSvgGenerator>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgWidget>
#include <QtSvg/QtSvg>

#include <QColorDialog>
#include <QMouseEvent>

#include <QStyle>
#include <QDesktopWidget>
#include "graphicsviewclass.h"
namespace Ui {
class MainWindow;

}



class MainWindow : public QMainWindow
{
    Q_OBJECT



protected:
    //virtual void wheelEvent(QWheelEvent* event);///ZOOM IN MOUSE


public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    RectTool *rt;
    EllTool *et;
    RoundRectTool *rrt;


    GraphicsViewClass *myWorkSpace;


    QAction* zoomUp;
    QAction* zoomDown;
    QAction* openFile;
    QAction* newFile;
    QAction* saveFileAs;
    QAction* saveFile;
    QAction* closeFile;
    QAction* setColor;
    QAction* deleteIt;



    //QColor currentColorOfBrush;


    Ui::MainWindow *ui;

    QString MODE = "";



    AskForSave *AskSaveDialog;

    //GraphicsViewClass* myWorkSpace;




private:







public slots:
    void FileOpen(bool);
    void FileNew(bool);
    void MakeNewFile();
    void FileClose(bool);
    void FileSaveAs(bool);
    void FileSave(bool);

    void open();
    void close();
    void newone();

   // void ChangeColor(QColor q);



};

#endif // MAINWINDOW_H
