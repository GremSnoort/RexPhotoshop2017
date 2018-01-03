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
#include <QPen>
#include <QBrush>

#include <QTextStream>

class CommonWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonWidget(QMainWindow *parent = nullptr);
    ~CommonWidget();


    QColor PenCOLOR = QColor(0, 0, 0);
    QColor BrushCOLOR = QColor(0, 255, 0);
    Qt::BrushStyle BrushSTYLE = Qt::SolidPattern;
    int PenWIDTH = 20;
    Qt::PenStyle PenSTYLE = Qt::SolidLine;
    Qt::PenCapStyle CapSTYLE = Qt::SquareCap;
    Qt::PenJoinStyle JointSTYLE = Qt::BevelJoin;


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


    QLabel *TitleOpacity;
    QSlider *Opacity;
    QLabel *LabelOpacity;

    QLabel *TitleBrushStyle;
    QComboBox *BrushStyleBox;

    QPen ReturnPen();
    QBrush ReturnBrush();


signals:

public slots:

    void SetPenColor(QColor Q);
    void SetBrushColor(QColor Q);
    void SetPenWidth(int w);
    void SetOpacity(int o);
    void SetPenStyle(QString s);
    void SetPenCapStyle(QString s);
    void SetPenJointStyle(QString s);
    void SetBrushStyle(QString s);

};

#endif // COMMONWIDGET_H
