#include "menu_Scene.h"
#include "Config.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPushButton>

menuScene::menuScene(QObject *parent)
    : QGraphicsScene{parent}
{

    window = dynamic_cast<MainWindow*>(parent);

    setSceneRect(-0.5*Config::Viewport::WIDTH,
                 -0.5*Config::Viewport::HEIGHT,
                 Config::Viewport::WIDTH,
                 Config::Viewport::HEIGHT);

    // Construct Scene Axis -----------------------
    int x_limit = 0.5 * width();
    int y_limit = 0.5 * height();
    lim = QPoint(x_limit,y_limit);
    x_axis = addLine(-x_limit,0,x_limit,0);
    x_axis->setZValue(10);
    y_axis = addLine(0,-y_limit,0,y_limit);
    y_axis->setZValue(10);
    // --------------------------------------------

    //setBackgroundBrush(QBrush(QColor(QColorConstants::Svg::lightsteelblue)));
    cursor = new QCursor();
    cursor->setShape(Qt::CrossCursor);

    pbutton = new QPushButton();
    pbutton->setGeometry(QRect(-x_limit*.7,y_limit*.9-50,100,50));
    pbutton->setText("Iniciar");
    addWidget(pbutton);
    QObject::connect(pbutton, &QPushButton::clicked, this, &menuScene::open);

    rect = new QGraphicsRectItem(-25,-25,50,50);
    addItem(rect);
    rect->setPos(-100,-100);
    rect->setBrush(Qt::red);

    _timer = new QTimer;
    QObject::connect(_timer, &QTimer::timeout, this, &QGraphicsScene::advance);
    _timer->start(1000 / Config::Viewport::FPS);
    qDebug() << "INIT";


}

void menuScene::setAxis(bool value)
{
    if(value){
        x_axis->show();
        y_axis->show();
    } else {
        x_axis->hide();
        y_axis->hide();
    }
}

void menuScene::open()
{
    qDebug() << "Button Press Event in Scene";
    window->changeScene(1);
}

void menuScene::mousePressEvent(QGraphicsSceneMouseEvent  *event){
    qDebug() << "mouse Press Event in Scene";
    qDebug() << event->pos();
    qDebug() << pbutton->pos();
    if(rect->pos() > window->mapFromGlobal(cursor->pos())-lim){
        qDebug() << "VERMELHO2";
    }
    qDebug() << window->mapFromGlobal(cursor->pos())-lim;
    if(rect->contains(window->mapFromGlobal(cursor->pos()-lim))){
        qDebug() << "VERMELHO";
    }
}

void menuScene::keyPressEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}

void menuScene::keyReleaseEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}
