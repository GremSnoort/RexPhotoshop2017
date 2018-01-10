#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include <QLabel>
#include <QSlider>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTextStream>
#include <QAction>

#include <QColorDialog>

#include "item.h"
#include "sceneclass.h"

#include "commonwidget.h"

class SelectionTool : public QObject
{
    Q_OBJECT
public:
    explicit SelectionTool(QMainWindow *parent = nullptr, CommonWidget*W = nullptr, SceneClass *scene = nullptr);


    CommonWidget*WID;
    SceneClass *sc;

    Item *it;

    QAction* clearSelection;
    QAction* removeItems;


    QPushButton *B;

    bool UP = false;
    bool draw = false;
    bool del = false;

signals:
    void TurnOffAllOthers(bool state);

public slots:

    void SetUP();
    void Press(qreal x, qreal y);
    void Move(qreal newX, qreal newY, qreal prX, qreal prY);
    void Release();
    void ClearSelection();
    void RemoveSelectedItems();

    void RepaintAll();

    void TurnOnOff(bool state);
};

#endif // SELECTIONTOOL_H
