#include "recttool.h"

RectTool::RectTool(SceneClass *scene) : Tool()
{    
    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/SquareAppleV2.png")));    
    B->move(10, 75);

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
