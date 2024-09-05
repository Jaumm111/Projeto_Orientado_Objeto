#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <QString>
#include <QGraphicsRectItem>

using namespace std;

#include "item.h"
#include "config.h"
#include "jogoscene.h"

class JogoScene;
class Item;

class Jogador : public QGraphicsRectItem{
private:
    QString nome;
    int ordem;
    int dinheiro = 0;
    int id;
    int num_voltas = 0;
    int posicao_tab;
    int posicao_casa = 0;
    bool preso = false;
    bool sua_vez = false;
    vector<Item *> iventario;
    JogoScene * scene;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public:
    Jogador(QString nome_,
            JogoScene * s,
            qreal x=-10, qreal y=-10,
            qreal width=20, qreal height=20,
            QGraphicsItem *parent = nullptr);
    QString getNome(){return nome;}
    void jogar_dados(JogoScene * scene);
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,int id_jog=0);
    void add_item();
    void mover_cadeia();
    void itemVisible(bool v);

};

#endif // JOGADOR_H
