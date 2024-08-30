#ifndef JOGADOR_H
#define JOGADOR_H

#include <vector>
#include <string>

using namespace std;

#include "item.h"
#include "config.h"

class Item;

class Jogador {
private:
    string nome;
    int ordem;
    int dinheiro = 0;
    int id;
    int num_voltas = 0;
    int posicao_tab;
    int posicao_casa = 0;
    bool preso = false;
    bool sua_vez = false;
    vector<Item *> iventario;
public:
    Jogador(string nome_, int tab_init);
    void jogar_dados();
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,int id_jog=0);
    void add_item();
    void mover_cadeia();

};

#endif // JOGADOR_H
