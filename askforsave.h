#ifndef ASKFORSAVE_H
#define ASKFORSAVE_H

#include <QWidget>
#include <QObject>


#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class AskForSave;
}

class AskForSave : public QWidget
{
    Q_OBJECT

signals:

    void Save(bool);
    void SaveAs(bool);

public slots:
     void MakeSave();
     void MakeSaveAs();

public:
    explicit AskForSave(QWidget *parent = 0);
    ~AskForSave();

private:
    Ui::AskForSave *ui;
};

#endif // ASKFORSAVE_H
