#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

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
    void clicar();
}
class I_Prop: public Item{
private:
    string tipo="propriedade";
public:
    void clicar();
}
class I_Carta: public Item{
private:
    string tipo="carta";
public:
    void clicar();
}
class I_Din: public Item{
private:
    string tipo="din";
public:
    void clicar();
}

class Tabuleiro{
private:
    int id;
    vector<Casa> casas;
    map<string, pair<int,int>>  status;
public:
    Tabuleiro(vector<Casa> casas_){
        casas = casas_;
        for(unsigned i=0;i <  casas.sizr(); i++){
            if (casas[i].tipo() == Casa::CasaType::PROPRIEDADE){
                status[casas[i].get_Cor()].first = 1 + status[casas[i].get_Cor()].first;
            }
        }


    }
}

class Casa{
private:
    int id;
public:
    enum {
        PROPRIEDADE,
        SORTE_REVES
    } CasaType;

    void Cair{

    }
    virtual Casa::CasaType tipo() = 0;

}
class Propriedade: public Casa{
    public:

    CasaType tipo() { return CasaType::PROPRIEDADE; }

}
class Sorte_Reves: public Casa{

public:
    CasaType tipo() { return CasaType::SORTE_REVES; }
}

class Baralho{
public:
    vector<Carta *> cartas;
    int pos;
}

int main() {


};
