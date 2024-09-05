#ifndef CONFIG_SCENE_H
#define CONFIG_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QCursor>

#include "mainwindow.h"
#include "botao.h"
#include "carddisplay.h"
#include "item.h"
#include "tabuleiro.h"

class Botao;
class Tabuleiro;
class CardDisplay;

class configScene : public QGraphicsScene
{
public:
    explicit configScene(QObject *parent = nullptr);

    void setAxis(bool value);


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void open();
private:

    QTimer          * _timer;
    Botao           * pbutton;
    Botao           * getTab;
    Tabuleiro       * tabuleiro;
    QCursor         * cursor;
    QPoint          lim;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;
    CardDisplay * rect;
    MainWindow      * window;

};

#endif // CONFIG_SCENE_H
