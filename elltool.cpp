#include "elltool.h"


EllToolRegistrator EllTool::ETReg = EllToolRegistrator();

EllTool::EllTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/RoundAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ONvsOFF()));
}

void EllTool::Press(qreal x, qreal y)
{
        it = new ItemEll(PenWID, BrWID, RcWID);
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

void EllTool::ONvsOFF()
{
    if(sc->ActiveTOOL != this)
    {
        sc->ActiveTOOL = this;
        B->setStyleSheet("background-color: rgb(46, 255, 0);");
        PenWID->PenWIDGET->show();
        BrWID->BrushWIDGET->show();
        RcWID->RoundWIDGET->hide();
    }
    else
    {
        sc->ActiveTOOL = new Tool(nullptr);
        B->setStyleSheet("");
        PenWID->PenWIDGET->hide();
        BrWID->BrushWIDGET->hide();
        RcWID->RoundWIDGET->hide();
    }
}

Tool *EllToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new EllTool(parent, scene, y);
}
