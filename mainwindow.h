#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "optionsfornewfile.h"
#include "graphicsviewclass.h"
#include "svgopen.h"

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


    QAction* zoomUp;
    QAction* zoomDown;
    QAction* openFile;
    QAction* newFile;
    QAction* saveFileAs;
    QAction* saveFile;
    QAction* closeFile;
    QAction* setColor;

    QColorDialog* ColorDialog;

    QColor currentColorOfBrush;




    bool IsModified = false;



private:
    Ui::MainWindow *ui;




    OptionsForNewFile *OptionsForm;
    GraphicsViewClass* myWorkSpace;



public slots:
    void FileOpen(bool);
    void FileNew(bool);
    void MakeNewFile();
    void FileClose(bool);
    void FileSaveAs(bool);
    void FileSave(bool);

    void ChangeColor(QColor q);


};

#endif // MAINWINDOW_H
