#include "polylinetool.h"
/*
class PolyLineToolRegistrator: public ToolRegistrator {
public:
    Tool* makeTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) { return new PolyLineTool(parent, W, scene) }
}

static ToorRegistrator pr(new PolyLineToolRegistrator);*/

PolyLineTool::PolyLineTool(QMainWindow *parent, SceneClass *scene) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/polyline.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 285);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release(qreal, qreal)), this, SLOT(Release(qreal, qreal)));



    sc = scene;
}

void PolyLineTool::TurnOnOff(bool state)
{
    UP = state;

    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(UP)
    {
        //WID->BrushWIDGET->hide();
        draw = false;
        drawFirst = true;
        emit TurnOffAllOthers(false);
    }
        //WID->BrushWIDGET->show();
}

void PolyLineTool::SetUP()
{
    TurnOnOff(!UP);
}

void PolyLineTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        if(QApplication::keyboardModifiers()==Qt::ControlModifier)drawFirst = true;
        if(drawFirst)
        {
            it = new Item(0);
            it->T = 4;
            sc->addItem(it);
            sc->items().first()->setFlag(QGraphicsItem::ItemIsSelectable, true);
            sc->items().first()->setFlag(QGraphicsItem::ItemIsMovable, true);
            drawFirst = false;
        }

        it->SetParameters();
        it->points<<QPoint(x, y);

        draw = true;
   }
}
void PolyLineTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        if(QApplication::keyboardModifiers()==Qt::ControlModifier)drawFirst = true;

        try
        {
            if(del)it->points.removeLast();
            it->points<<QPoint(newX, newY);
            del = true;
        }catch(...)
        {

        }
    }
}

void PolyLineTool::Release(qreal newX, qreal newY)
{
    if(UP&&draw)
    {
        it->points<<QPoint(newX, newY);        
        del = false;
        if(QApplication::keyboardModifiers()==Qt::ControlModifier)draw = false;
    }
}

