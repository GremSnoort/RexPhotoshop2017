#include "recttool.h"

RectToolRegistrator RectTool::RTReg = RectToolRegistrator();

RectTool::RectTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ON()));
}

void RectTool::Press(qreal x, qreal y)
{    
        it = new ItemRect();
        it->SetParameters();
        it->SetYX(x, y);
        sc->addItem(it);


        sc->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable, true);

}
void RectTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
        it->SetParameters();
        it->SetYX(prX, prY);
        it->dx = newX-prX;
        it->dy = newY-prY;
}

void RectTool::Release()
{

}

void RectTool::ON()
{    
        sc->ActiveTOOL = this;
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        ItemBaseClass::PWID->PenWIDGET->show();
        ItemBaseClass::BWID->BrushWIDGET->show();
        ItemBaseClass::RWID->RoundWIDGET->hide();
}

void RectTool::OFF()
{
        B->setStyleSheet("");
}

Tool *RectToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new RectTool(parent, scene, y);
}

