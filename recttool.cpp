#include "recttool.h"

RectToolRegistrator RectTool::RTReg = RectToolRegistrator();

RectTool::RectTool(QMainWindow *parent, SceneClass *scene, int y) : Tool()
{    
    B = new QPushButton(parent);

    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/SquareAppleV2.png")));    
    B->move(10, y);

    sc = scene;


}

void RectTool::Press(qreal x, qreal y)
{    
        it = new ItemRect(BrWID);
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

Tool *RectToolRegistrator::makeTool(QMainWindow *parent, SceneClass *scene, int y)
{
    return new RectTool(parent, scene, y);
}

