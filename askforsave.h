#ifndef ASKFORSAVE_H
#define ASKFORSAVE_H

#include <QWidget>
#include <QObject>

#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>

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
     void MakeSave();
     void MakeSaveAs();
     void MakeCancel();

public:
    explicit AskForSave(QMainWindow *parent);
    ~AskForSave();


private:
    Ui::AskForSave *ui;
};

#endif // ASKFORSAVE_H
