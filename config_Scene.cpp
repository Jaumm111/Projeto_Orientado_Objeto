#include "config_Scene.h"
#include "config.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPushButton>

configScene::configScene(QObject *parent)
    : QGraphicsScene{parent}
{
    window = dynamic_cast<MainWindow*>(parent);

    setSceneRect(-0.5*Config::Viewport::WIDTH,
                 -0.5*Config::Viewport::HEIGHT,
                 Config::Viewport::WIDTH,
                 Config::Viewport::HEIGHT);

    // Construct Scene Axis -----------------------
    int x_limit = (0.5 * width())+12;
    int y_limit = (0.5 * height())+12;
    lim = QPoint(x_limit,y_limit);
    x_axis = addLine(-x_limit,0,x_limit,0);
    x_axis->setZValue(10);
    y_axis = addLine(0,-y_limit,0,y_limit);
    y_axis->setZValue(10);
    // --------------------------------------------

    //setBackgroundBrush(QBrush(QColor(QColorConstants::Svg::lightsteelblue)));
    cursor = new QCursor();
    cursor->setShape(Qt::CrossCursor);

    pbutton = new Botao(0,0,100,50);
    pbutton->setPos(-x_limit*.7,y_limit*.9-50);
    pbutton->setText("Menu");
    pbutton->addPixMap(QPixmap(":/images/botao.jfif"));
    pbutton->set_Window(window);
    pbutton->set_Scene(0);
    addItem(pbutton);

    pbutton = new Botao(0,0,100,50);
    pbutton->setPos(x_limit*.7-100,y_limit*.9-50);
    pbutton->setText("Jogo");
    pbutton->addPixMap(QPixmap(":/images/botao.jfif"));
    pbutton->set_Window(window);
    pbutton->set_Scene(2);
    addItem(pbutton);


    //QPixmap pixmap2(":/images/saida_livre.jfif");
    /*rect = new CardDisplay(0,0,86,121);
    addItem(rect);
    rect->setPos(100,-100);
    rect->setCursor(cursor);
    rect->set_Window(window,lim);*/

    //rect->addPixMap(pixmap2);


    _timer = new QTimer;
    QObject::connect(_timer, &QTimer::timeout, this, &QGraphicsScene::advance);
    _timer->start(1000 / Config::Viewport::FPS);
    qDebug() << "INIT";


}

void configScene::setAxis(bool value)
{
    if(value){
        x_axis->show();
        y_axis->show();
    } else {
        x_axis->hide();
        y_axis->hide();
    }
}

void configScene::open()
{
    qDebug() << "Button Press Event in Scene";
    this->setAxis(false);
}

void configScene::mousePressEvent(QGraphicsSceneMouseEvent  *event){
    qDebug() << "mouse Press Event in Scene";
    qDebug() << event->pos();
    qDebug() << pbutton->pos();
    qDebug() << (cursor->pos());
}

void configScene::keyPressEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}

void configScene::keyReleaseEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}
