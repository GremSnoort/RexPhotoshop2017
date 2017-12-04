#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "optionsfornewfile.h"


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

    QGraphicsScene *scene;
    QAction* zoomUp;
    QAction* zoomDown;
    QAction* openFile;
    QAction* newFile;
    QAction* saveFileAs;
    QAction* setColor;

    QColorDialog* ColorDialog;

    QColor currentColorOfBrush;


    int X = 0;
    int Y = 0;



private:
    Ui::MainWindow *ui;

    QString fileNameToOpen;
    int CountOfZoom = 0;

    OptionsForNewFile *OptionsForm;



public slots:
    void FileOpen(bool);
    void FileNew(bool);
    void MakeNewFile();
    void FileClose(bool);
    void FileSaveAs(bool);
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);

    void SetColorView();

};

#endif // MAINWINDOW_H
