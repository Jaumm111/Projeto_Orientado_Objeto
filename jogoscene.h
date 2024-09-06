#ifndef JOGOSCENE_H
#define JOGOSCENE_H

#include "mainwindow.h"
#include "botao.h"
#include "carddisplay.h"
#include "item.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "baralho.h"

using namespace std;

class Botao;
class Jogador;
class Util_b;
class Tabuleiro;
class CardDisplay;
class MainWindow;
class Baralho;

class JogoScene : public QGraphicsScene
{
public:
    explicit JogoScene(QObject *parent = nullptr);

    void setAxis(bool value);
    void getTab(QString fi);
    void getBaralho(QString fi);
    void nextJog();
    bool getEspera();
    void setEspera(bool a);
    void setDados(int d_1, int d_2);


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void open();
private:
    bool espera = false;
    vector<Jogador *> jog;
    QTimer          * _timer;
    Botao           * pbutton;
    Util_b          * dados;
    Tabuleiro       * tabuleiro;
    Baralho         * baralho;
    QCursor         * cursor;
    CardDisplay     * d1;
    CardDisplay     * d2;
    QPoint          lim;
    int             atual;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;
    CardDisplay * rect;
    MainWindow      * window;

};

#endif // JOGOSCENE_H
