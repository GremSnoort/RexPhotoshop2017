#include "selectiontool.h"

SelectionToolRegistrator SelectionTool::STReg = SelectionToolRegistrator();

SelectionTool::SelectionTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Selection.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ON()));
    //connect(scene, SIGNAL(Release()), this, SLOT(RepaintAll()));
    connect(ItemBaseClass::PWID, SIGNAL(Changed()), this, SLOT(RepaintAll()));
    connect(ItemBaseClass::BWID, SIGNAL(Changed()), this, SLOT(RepaintAll()));
    connect(ItemBaseClass::RWID, SIGNAL(Changed()), this, SLOT(RepaintAll()));

    clearSelection = new QAction(parent);
    clearSelection->setShortcut(tr("Ctrl+D"));
    parent->addAction(clearSelection);
    connect(clearSelection, SIGNAL(triggered(bool)), this, SLOT(ClearSelection()));

    it = new ItemSelection();
    sc->addItem(it);
    it->hide();
}

void SelectionTool::Press(qreal x, qreal y)
{
    QPainterPath P(QPoint(x, y));
    P.addRect(x, y, 1, 1);
    sc->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());

    it->SetYX(x, y);
    it->show();
    it->setZValue(1);

}
void SelectionTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    QPainterPath P(QPoint(prX, prY));
    P.addRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
    sc->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());

    it->SetYX(prX, prY);
    it->dx = newX-prX;
    it->dy = newY-prY;
}

void SelectionTool::Release()
{

}

void SelectionTool::ON()
{
    sc->ActiveTOOL = this;
    foreach(Tool* T, ToolRegistrator::registry)
    {
        if(T!=this)T->OFF();
    }
    B->setStyleSheet("background-color: rgb(46, 255, 0);");
    ItemBaseClass::PWID->PenWIDGET->show();
    ItemBaseClass::BWID->BrushWIDGET->show();
    ItemBaseClass::RWID->RoundWIDGET->show();
}

void SelectionTool::OFF()
{
        B->setStyleSheet("");
        it->hide();
        sc->clearSelection();
}

void SelectionTool::RepaintAll()
{
    foreach(QGraphicsItem*IT, sc->selectedItems())
    {
        dynamic_cast<ItemBaseClass*>(IT)->SetParameters();
    }
}

void SelectionTool::ClearSelection()
{
    it->hide();
    sc->clearSelection();
}

Tool *SelectionToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new SelectionTool(parent, scene, y);
}






/*




SelectionTool::SelectionTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
{
    WID = W;
    sc = scene;

    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Selection.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 355);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release(qreal, qreal)), this, SLOT(Release()));

    //



    removeItems = new QAction(parent);
    removeItems->setShortcut(tr("X"));
    parent->addAction(removeItems);
    connect(removeItems, SIGNAL(triggered(bool)), this, SLOT(RemoveSelectedItems()));
}

void SelectionTool::RemoveSelectedItems()
{
    while(sc->selectedItems().size()>0)
    {
        sc->removeItem(sc->selectedItems().first());
    }
    ClearSelection();
}

void SelectionTool::ClearSelection()
{
    sc->clearSelection();
    if(del)
    {
        sc->removeItem(sc->items().first());
        del = false;
    }
}

void SelectionTool::TurnOnOff(bool state)
{
    UP = state;

    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(UP)
    {
        emit TurnOffAllOthers(false);
        WID->RoundWIDGET->show();
    }else
        ClearSelection();
}

void SelectionTool::SetUP()
{
    UP ? TurnOnOff(false) : TurnOnOff(true);
}

void SelectionTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        if(del)sc->removeItem(sc->items().first());
        QPainterPath P(QPoint(x, y));

        P.addRect(x, y, 1, 1);
        sc->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());

        it = new Item(0, WID);
        it->T = 0;
        it->x = x;
        it->y = y;
        it->dx = 1;
        it->dy = 1;
        sc->addItem(it);

        del = true;
        draw = true;
   }
}
void SelectionTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP&&draw)
    {
        QPainterPath P(QPoint(prX, prY));
        P.addRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
        sc->setSelectionArea(P, Qt::IntersectsItemShape, QTransform());

        it->x = prX;
        it->y = prY;
        it->dx = newX-prX;
        it->dy = newY-prY;
    }
}


void SelectionTool::Release()
{
    draw = false;
}

*/
