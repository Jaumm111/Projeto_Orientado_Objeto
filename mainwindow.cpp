#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    _scene = new menuScene(this);
    //_scene->setAxis(false);
    _viewport = new QGraphicsView(this);
    _viewport->setScene(_scene);
    _viewport->setBackgroundBrush(QPixmap(":/images/space.jpg"));
    _layout = new QVBoxLayout(this);
    _layout->addWidget(_viewport);
    setMouseTracking(true);
    setLayout(_layout);
    setFixedSize(sizeHint());
    setWindowTitle("B_I");
}

MainWindow::~MainWindow()
{
}

