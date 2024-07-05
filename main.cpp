#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <QApplication>
#include <QtWidgets>

using namespace std;

class Jogador {
private:
    string nome;
    int ordem;
    int dinheiro;
    int id;
    int posicao_tab;
    int posicao_casa;
    bool preso;
    bool sua_vez;
    vector<Item *> iventario;
public:
    Jogador() {
    }
    void jogar_dados();
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,int id_jog = 0);
    void add_item();

};

void Jogador::jogar_dados(){

}

void Jogador::mover_peao(){

}

void Jogador::receber_dinheiro(){

}

void Jogador::pagar(int num, int id_jog=0){

}

class Item{
private:
    string tipo;
public:
    void usar();
}
class I_Prop: public Item{
private:
    string tipo="propriedade";
public:
}
class I_

class Tabuleiro{
private:
    int id;
    vector<Casa *> 
}

class Casa{
private:
    int id;
public:
    void Cair{

    }

}
class Propriedade: public Casa{

}
class Sorte_Reves: public Casa{

}

class Baralho{
public:
    vector<Carta *> cartas;
    int pos;
}

int main() {


};
