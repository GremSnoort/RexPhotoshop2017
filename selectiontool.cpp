#include "selectiontool.h"

SelectionTool::SelectionTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene, QWidget *wW) : QObject(parent)
{
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap(QCoreApplication::applicationDirPath()+"/Pics/Selection.png")));
    B->setIconSize(QSize(50, 50));
    B->adjustSize();
    B->move(10, 285);
    B->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(B, SIGNAL(released()), this, SLOT(SetUP()));
    connect(scene, SIGNAL(Press(qreal,qreal)), this, SLOT(Press(qreal,qreal)));
    connect(scene, SIGNAL(Move(qreal,qreal,qreal,qreal)), this, SLOT(Move(qreal,qreal,qreal,qreal)));
    connect(scene, SIGNAL(Release()), this, SLOT(Release()));

    WID = W;
    sc = scene;

    connect(WID, SIGNAL(Changed()), this, SLOT(RepaintAll()));


    RB = new QRubberBand(QRubberBand::Rectangle, wW);
    RB->setStyleSheet("color: rgb(160, 200, 180);");

}

void SelectionTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
    if(!UP)RB->hide();
}

void SelectionTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        QPainterPath P(QPoint(x, y));

        P.setFillRule(Qt::WindingFill);
        P.addRect(x, y, 1, 1);
        sc->setSelectionArea(P, Qt::IntersectsItemBoundingRect, QTransform());

        RB->setGeometry(QRect(x, y, 1, 1));
        RB->show();

   }
}
void SelectionTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP)
    {
        QPainterPath P(QPoint(prX, prY));
        P.setFillRule(Qt::WindingFill);
        P.addRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
        sc->setSelectionArea(P, Qt::IntersectsItemBoundingRect, QTransform());

        RB->setGeometry(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));

    }
}

void SelectionTool::Release()
{

}

void SelectionTool::RepaintAll()
{
    for(int i=0; i<sc->selectedItems().size(); i++)
    {
        dynamic_cast<Item*>(sc->selectedItems().at(i))->SetParameters();
    }
   /* foreach (Item*it, dynamic_cast<QList<Item*>>(sc->selectedItems())) {
        it->SetParameters();
    }*/
}
