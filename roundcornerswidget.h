#ifndef ROUNDCORNERSWIDGET_H
#define ROUNDCORNERSWIDGET_H

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

class RoundCornersWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit RoundCornersWidget(QMainWindow *parent = nullptr, int y = 0);
    ~RoundCornersWidget();

    QWidget *RoundWIDGET;//round

    int ROUNDCornersX = 25;
    int ROUNDCornersY = 25;

    QLabel *TitleRoundCornersX;
    QSlider *RoundCornersX;
    QLabel *LabelRoundCornersX;
    QLabel *TitleRoundCornersY;
    QSlider *RoundCornersY;
    QLabel *LabelRoundCornersY;

signals:

    void Changed();

public slots:

    void SetRoundCornersX(int r);
    void SetRoundCornersY(int r);
};

#endif // ROUNDCORNERSWIDGET_H
