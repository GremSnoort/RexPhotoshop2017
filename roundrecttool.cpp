#include "roundrecttool.h"

RoundRectToolRegistrator RoundRectTool::RRTReg = RoundRectToolRegistrator();

RoundRectTool::RoundRectTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/rounded-rectangle.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ON()));
}

void RoundRectTool::Press(qreal x, qreal y)
{
        it = new ItemRoundRect();
        it->SetParameters();
        it->SetYX(x, y);
        sc->addItem(it);

        sc->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable, true);
}

void RoundRectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
        it->SetParameters();
        it->SetYX(std::min(newX, prX), std::min(newY, prY));
        it->dx = abs(newX-prX);
        it->dy = abs(newY-prY);
}

void RoundRectTool::Release()
{

}

void RoundRectTool::ON()
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

void RoundRectTool::OFF()
{
        B->setStyleSheet("");
}

Tool *RoundRectToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new RoundRectTool(parent, scene, y);
}
