#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>

//class MainWindow;

#include "menu_Scene.h"
#include "config_Scene.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void changeScene(int escolha);

private:
    QVector<QGraphicsScene *> _scenes;
    QGraphicsView * _viewport;
    QVBoxLayout * _layout;
};
#endif // MAINWINDOW_H
