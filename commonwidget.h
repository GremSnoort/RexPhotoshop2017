#ifndef COMMONWIDGET_H
#define COMMONWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QColorDialog>
#include <QColor>

class CommonWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonWidget(QMainWindow *parent = nullptr);


    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(0, 255, 0);
    int PenWIDTH = 0;

    QColorDialog* CDPen;
    QColorDialog* CDBrush;


    QWidget *WID;


    QPushButton *PenColor;
    QPushButton *BrushColor;

    QSlider *PenWidth;
    QLabel *LabelPenWIDTH;


signals:

public slots:

    void SetPenColor(QColor Q);
    void SetBrushColor(QColor Q);
    void SetPenWidth(int w);

};

#endif // COMMONWIDGET_H
