#ifndef ASKFORSAVE_H
#define ASKFORSAVE_H

#include <QWidget>
#include <QObject>
#include <QDialog>
#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>
#include <QAbstractButton>

namespace Ui {
class AskForSave;
}

class AskForSave : public QMainWindow
{
    Q_OBJECT

signals:

    void Save(bool);
    void SaveAs(bool);
    void Cancel();

public slots:
     void MakeSignal(QAbstractButton*b);

public:
    explicit AskForSave(QMainWindow *parent);
    ~AskForSave();


private:
    Ui::AskForSave *ui;
};

#endif // ASKFORSAVE_H
