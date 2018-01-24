#ifndef TOOLREGISTRATOR_H
#define TOOLREGISTRATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QList>
#include "tool.h"

class ToolRegistrator
{
public:
    explicit ToolRegistrator();
    static QList<Tool *> registry;
    virtual Tool * makeTool(QMainWindow *parent = nullptr, SceneClass *scene = nullptr, int y = 0) =0;

};



#endif // TOOLREGISTRATOR_H

