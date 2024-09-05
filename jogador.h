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
    bool denovo= false;
    int num_voltas = 0;
    int repetir = 0;
    QString cor;
    int posicao_tab;
    int posicao_casa = 0;
    bool preso = false;
    bool sua_vez = false;
    vector<Item *> iventario;
    JogoScene * scene;
    int x_;
    int y_;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public:
    Jogador(QString nome_,
            QString cor_,
            JogoScene * s,
            qreal x=-10, qreal y=-10,
            qreal width=20, qreal height=20,
            QGraphicsItem *parent = nullptr);
    QString getNome(){return nome;}
    JogoScene * getScene(){return scene;}
    bool getDenovo(){return denovo;}
    void jogar_dados(JogoScene * scene);
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,Jogador * j = nullptr);
    void add_item(Item * i);
    void mover_cadeia();
    void itemVisible(bool v);

};

#endif // JOGADOR_H
