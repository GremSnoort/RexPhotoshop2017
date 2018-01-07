#include "selectiontool.h"

SelectionTool::SelectionTool(QMainWindow *parent, CommonWidget *W, SceneClass *scene) : QObject(parent)
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
}

void SelectionTool::SetUP()
{
    UP = !UP;
    B->setStyleSheet(UP ? "background-color: rgb(46, 255, 0);" : "");
}

void SelectionTool::Press(qreal x, qreal y)
{
    if(UP)
    {
        QPainterPath P(QPoint(x, y));
        P.addRect(x, y, 1, 1);
        sc->setSelectionArea(P, Qt::IntersectsItemBoundingRect, QTransform());
        //sc->items().first()->setSelected(true);
        QTextStream out(stdout);
        out<<"1111Items!!"<<sc->selectionArea().boundingRect().width()<<"....."<<sc->selectionArea().boundingRect().height()<<endl;

   }
}
void SelectionTool::Move(qreal newX, qreal newY, qreal prX, qreal prY)
{
    if(UP)
    {
        QPainterPath P(QPoint(prX, prY));
        P.addRect(std::min(prX, newX), std::min(prY, newY), abs(prX-newX), abs(prY-newY));
        sc->setSelectionArea(P, Qt::IntersectsItemBoundingRect, QTransform());
        //sc->items().first()->setSelected(true);
        QTextStream out(stdout);
        out<<"1111Items!!"<<sc->items().first()->sceneBoundingRect().width()<<"..."<<sc->items().first()->sceneBoundingRect().height()<<"______________"<<sc->selectionArea().boundingRect().width()<<"....."<<sc->selectionArea().boundingRect().height()<<"-----"<<sc->selectedItems().size()<<endl;

    }
}

void SelectionTool::Release()
{

}
