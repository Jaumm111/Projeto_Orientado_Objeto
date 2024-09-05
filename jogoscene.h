#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include "mainwindow.h"
#include "botao.h"
#include "carddisplay.h"
#include "item.h"
#include "tabuleiro.h"
#include "jogador.h"

using namespace std;

class Botao;
class Jogador;
class Util_b;
class Tabuleiro;
class CardDisplay;
class MainWindow;

class JogoScene : public QGraphicsScene
{
public:
    explicit JogoScene(QObject *parent = nullptr);

    void setAxis(bool value);
    void getTab(QString fi);
    void nextJog();


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void open();
private:
    vector<Jogador *> jog;
    QTimer          * _timer;
    Botao           * pbutton;
    Util_b           * dados;
    Tabuleiro       * tabuleiro;
    QCursor         * cursor;
    QPoint          lim;
    int             atual;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;
    CardDisplay * rect;
    MainWindow      * window;

};

#endif // JOGOSCENE_H
