#include "dialog.h"
#include "ui_dialog.h"
#include "rectitem.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200, -200, 400, 400);

    QPen pen = QPen(Qt::red);
    scene->addLine(QLineF(scene->sceneRect().topLeft(), scene->sceneRect().topRight()), pen);
    scene->addLine(QLineF(scene->sceneRect().topRight(), scene->sceneRect().bottomRight()), pen);
    scene->addLine(QLineF(scene->sceneRect().bottomRight(), scene->sceneRect().bottomLeft()), pen);
    scene->addLine(QLineF(scene->sceneRect().bottomLeft(), scene->sceneRect().topLeft()), pen);

    int item_count = 25;
    for(int i = 0; i < item_count; ++i)
    {
        RectItem* item = new RectItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}
