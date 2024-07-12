#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <stdlib.h>

#include <QApplication>
#include <QtWidgets>

using namespace std;

int dice;
int max_rep;
int dinheiro_init;
<vector int> tab_seq;

class Jogador {
private:
    string nome;
    int ordem;
    int dinheiro;
    int id;
    int posicao_tab;
    int posicao_casa = 0;
    bool preso = false;
    bool sua_vez = false;
    vector<Item *> iventario;
public:
    Jogador(string nome_, int tab_init) {
        nome = nome_;
        dinheiro = dinheiro_init;
        posicao_tab = tab_init;
    }
    void jogar_dados();
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,int id_jog = 0);
    void add_item();
    void mover_cadeia();

};

void Jogador::jogar_dados(){
    int d1;
    int d2;
    int repetir = 0;
    if (preso){
        d1 = rand() % 6 +1;
        d2 = rand() % 6 +1;
    }
    else{
        d1 = rand() % dice +1;
        d2 = rand() % dice +1;
    }
    while (repetir < max_rep){
        
        if (d1 == d2){
            repetir++;
            if (preso){
                repetir--;
                preso=false;
            }
            else{
                if (repetir == max_rep)
                    mover_cadeia()
                else
                    mover_peao(d1+d2)
            }
            
        }
        else{
            if (!preso)
                mover_peao(d1+d2)
            break;
        }
        if (repetir == max_rep)
            mover_cadeia()
        d1 = rand() % dice +1;
        d2 = rand() % dice +1;
    }
}
void Jogador::mover_cadeia(){
    preso = true;
}
void Jogador::mover_peao(int num_casas){

}

void Jogador::receber_dinheiro(){

}

void Jogador::pagar(int num, int id_jog=0){

}

class Item{
public:
    enum{
        PROPRIEDADE,
        CARTA,
        DINHEIRO
    }type_i;
    void clicar();
    virtual type_i tipo() = 0;
}
class I_Prop: public Item{
private:
    string tipo="propriedade";
    Propriedade * prop;
public:
    void clicar();
    type_i tipo(){return type_i::PROPRIEDADE};
}
class I_Carta: public Item{
private:
    string tipo="carta";
public:
    void clicar();
    type_i tipo(){return type_i::CARTA};
}
class I_Din: public Item{
private:
    string tipo="din";
public:
    void clicar();
    type_i tipo(){return type_i::DINHEIRO};
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
                status[casas[i].get_Cor()].second = 0;
            }
        }
    }
    pair<int, int> verificar_status(string cor){
        return status[cor]
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

    virtual void Cair() = 0;
    virtual Casa::CasaType tipo() = 0;

}
class Propriedade: public Casa{
private:
    int preco;
    vector<int> aluguel;
    int num_estacoes;
    int hipoteca;
    string nome;
    string cor;
    P_Type tipo_p;
    Jogador dono; 
public:
    enum {
        PADRAO,
        CIA,
        USINA
    } P_Type;
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
    srand(time(NULL));
    dice = 6;

};
