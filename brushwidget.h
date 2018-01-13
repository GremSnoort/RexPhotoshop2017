#ifndef BRUSHWIDGET_H
#define BRUSHWIDGET_H

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

class BrushWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit BrushWidget(QMainWindow *parent = nullptr, int y = 0);
    ~BrushWidget();

    QWidget *BrushWIDGET;

    QColor BrushCOLOR = QColor(0, 255, 0);
    Qt::BrushStyle BrushSTYLE = Qt::SolidPattern;
    QColorDialog* CDBrush;
    QPushButton *BrushColor;
    QLabel *TitleBrushStyle;
    QComboBox *BrushStyleBox;

    QBrush ReturnBrush();

signals:
    void Changed();

public slots:

    void SetBrushColor(QColor Q);
    void SetBrushStyle(QString s);

signals:

public slots:
};

#endif // BRUSHWIDGET_H
