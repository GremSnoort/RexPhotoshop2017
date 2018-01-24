#include "recttool.h"

RectToolRegistrator RectTool::RTReg = RectToolRegistrator();

RectTool::RectTool(QMainWindow *parent, SceneClass *scene, int y) : Tool(parent)
{
    B = new QPushButton(parent);
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    B->move(10, y);

    sc = scene;

    connect(B, SIGNAL(released()), this, SLOT(ONvsOFF()));
}

void RectTool::Press(qreal x, qreal y)
{    
        it = new ItemRect(BrWID, PenWID);
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

void RectTool::ONvsOFF()
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

Tool *RectToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new RectTool(parent, scene, y);
}

