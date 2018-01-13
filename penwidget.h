#ifndef PENWIDGET_H
#define PENWIDGET_H

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

class PenWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit PenWidget(QMainWindow *parent = nullptr, int y = 0);
    ~PenWidget();

    QWidget *PenWIDGET;//pen

    QColor PenCOLOR = QColor(0, 0, 0);
    Qt::PenStyle PenSTYLE = Qt::SolidLine;
    Qt::PenCapStyle CapSTYLE = Qt::SquareCap;
    Qt::PenJoinStyle JointSTYLE = Qt::BevelJoin;
    int PenWIDTH = 20;

    QColorDialog* CDPen;

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

    qreal OPACITY = 1;

    QLabel *TitleOpacity;
    QSlider *Opacity;
    QLabel *LabelOpacity;

    int ANGLE = 0;
    QLabel *TitleAngle;
    QSlider *Angle;
    QLabel *LabelAngle;

    QPen ReturnPen();

signals:

    void Changed();

public slots:

    void SetPenColor(QColor Q);
    void SetPenWidth(int w);
    void SetPenStyle(QString s);
    void SetPenCapStyle(QString s);
    void SetPenJointStyle(QString s);

    void SetOpacity(int o);
    void SetAngle(int a);
};

#endif // PENWIDGET_H
