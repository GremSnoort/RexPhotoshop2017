#ifndef MAINWINDOW_H
#define MAINWINDOW_H


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
    QAction* saveFileAs;
    QAction* setColor;

    QColorDialog* ColorDialog;





private:
    Ui::MainWindow *ui;

    QString fileNameToOpen;


public slots:
    void FileOpen(bool);
    void FileClose(bool);
    void FileSaveAs(bool);
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);

    void SetColorView(QColor);

};

#endif // MAINWINDOW_H
