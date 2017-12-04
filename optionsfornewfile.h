#ifndef OPTIONSFORNEWFILE_H
#define OPTIONSFORNEWFILE_H

#include <QWidget>
#include <QObject>
#include <QValidator>
#include <QString>

#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class OptionsForNewFile;
}

class OptionsForNewFile : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsForNewFile(QWidget *parent = 0);
    ~OptionsForNewFile();

    int H = 0;
    int W = 0;


signals:

    void Signal();


public slots:
    void Limit(QString);
    void pressedOK();

    void pressedCancel();
    void EmitNewSignal();

private:
    Ui::OptionsForNewFile *ui;
};

#endif // OPTIONSFORNEWFILE_H
