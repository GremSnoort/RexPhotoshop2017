#include "elltool.h"


EllToolRegistrator EllTool::ETReg = EllToolRegistrator();

EllTool::EllTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ON()));
}

void EllTool::Press(qreal x, qreal y)
{
        it = new ItemEll();
        it->SetParameters();
        it->SetYX(x, y);
        sc->addItem(it);

        sc->items().first()->setFlag(QGraphicsRectItem::ItemIsSelectable, true);
}

void EllTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
        it->SetParameters();
        it->SetYX(prX, prY);
        it->dx = newX-prX;
        it->dy = newY-prY;
}

void EllTool::Release()
{

}

void EllTool::ON()
{
        sc->ActiveTOOL = this;
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        ItemBaseClass::PWID->PenWIDGET->show();
        ItemBaseClass::BWID->BrushWIDGET->show();
        ItemBaseClass::RWID->RoundWIDGET->hide();
}

void EllTool::OFF()
{
        B->setStyleSheet("");
}

Tool *EllToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new EllTool(parent, scene, y);
}
