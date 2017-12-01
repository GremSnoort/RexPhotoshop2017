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

private:
    Ui::MainWindow *ui;

    QString fileNameToOpen;


public slots:
    void FileOpen(bool);
    void zoomUpEvent(bool);
    void zoomDownEvent(bool);

};

#endif // MAINWINDOW_H
