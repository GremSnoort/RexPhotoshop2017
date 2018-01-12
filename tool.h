#ifndef TOOL_H
#define TOOL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Tool : public QObject
{
    Q_OBJECT
public:
    explicit Tool(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TOOL_H