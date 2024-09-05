#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    _scenes.push_back(new menuScene(this));
    _scenes.push_back(new configScene(this));
    _scenes.push_back(new JogoScene(this));
    //_scene->setAxis(false);
    _viewport = new QGraphicsView(this);
    _viewport->setScene(_scenes[0]);
    //_viewport->setBackgroundBrush(QPixmap(":/images/space.jpg"));
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
void MainWindow::changeScene(int escolha){
    _viewport->setScene(_scenes[escolha]);
}

