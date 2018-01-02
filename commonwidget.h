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
#include <QComboBox>

#include <QTextStream>

class CommonWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonWidget(QMainWindow *parent = nullptr);
    ~CommonWidget();


    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(0, 255, 0);
    int PenWIDTH = 20;
    qreal OPACITY = 1;

    QColorDialog* CDPen;
    QColorDialog* CDBrush;


    QWidget *WID;


    QPushButton *PenColor;

    QLabel *TitlePenWIdth;
    QSlider *PenWidth;
    QLabel *LabelPenWIDTH;

    QLabel *TitlePenStyle;
    QComboBox *PenStyleBox;


    QLabel *TitleCapStyle;
    QComboBox *CapStyleBox;

    QLabel *TitleJointStyle;
    QComboBox *JointStyleBox;

    QPushButton *BrushColor;



    QSlider *Opacity;
    QLabel *LabelOpacity;


signals:

public slots:

    void SetPenColor(QColor Q);
    void SetBrushColor(QColor Q);
    void SetPenWidth(int w);
    void SetOpacity(int o);

};

#endif // COMMONWIDGET_H
