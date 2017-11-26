#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QAction>
#include <QTextStream>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene *scene;

private:
    Ui::MainWindow *ui;

    QString fileNameToOpen;


public slots:
    void FileOpen(bool b);

};

#endif // MAINWINDOW_H
