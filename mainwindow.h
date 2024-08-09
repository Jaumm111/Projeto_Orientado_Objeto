#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "menu_Scene.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    menuScene * _scene;
    QGraphicsView * _viewport;
    QVBoxLayout * _layout;
};
#endif // MAINWINDOW_H
