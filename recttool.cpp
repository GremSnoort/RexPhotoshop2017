#include "recttool.h"

RectTool::RectTool(QMainWindow *parent) : QMainWindow(parent)
{

    scene = new SceneClass();
    B = new QPushButton(parent);

    B->setIcon(QIcon(QPixmap("/home/kor/Desktop/Qt_Proj/RexPhotoshop2017/SquareAppleV2.png")));
    B->setIconSize(QSize(50, 50));

    B->adjustSize();
    B->move(10, 290);

    connect(B, SIGNAL(toggled(bool)), this, SLOT(SetUP(bool)));
    //connect(MainWindow::getScene(), SIGNAL(Press(QGraphicsSceneMouseEvent*)), this, SLOT(Press(QGraphicsSceneMouseEvent*)));


}

void RectTool::SetUP(bool b)
{
    UP = b;
}

void RectTool::Press(QGraphicsSceneMouseEvent *event, SceneClass *sc)
{
    QTextStream out(stdout);
    out<<"!!!"<<endl;
    this->setScene(sc);
    sc->addRect(event->scenePos().x(), event->scenePos().y(), 10, 10, QPen(Qt::black), QBrush(QColor(134, 234, 234)));
    /*scene = MainWindow::getScene();

    MainWindow::setScene(scene);*/
}
