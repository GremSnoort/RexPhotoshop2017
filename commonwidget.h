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
#include <QCoreApplication>

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
    int ROUNDCornersX = 25;
    int ROUNDCornersY = 25;
    int ANGLE=25;

    QColorDialog* CDPen;
    QColorDialog* CDBrush;


    QWidget *WID;

    QWidget *PenWIDGET;//pen


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


    QWidget *RoundWIDGET;//round


    QLabel *TitleRoundCornersX;
    QSlider *RoundCornersX;
    QLabel *LabelRoundCornersX;
    QLabel *TitleRoundCornersY;
    QSlider *RoundCornersY;
    QLabel *LabelRoundCornersY;

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
    void SetRoundCornersX(int r);
    void SetRoundCornersY(int r);

};

#endif // COMMONWIDGET_H
