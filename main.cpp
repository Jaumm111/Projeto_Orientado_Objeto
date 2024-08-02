#include "mainwindow.h"

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

class Propriedade;

class Item{
public:
    typedef enum Type_i{
        PROPRIEDADE,
        CARTA,
        DINHEIRO
    }Type_i;
    void clicar();
    virtual int get_valor() = 0;
    virtual Type_i tipo() = 0;
};
class I_Prop: public Item{
private:
    Propriedade * prop;
public:
    void clicar();
    Type_i tipo(){return Type_i::PROPRIEDADE;}
};
class I_Carta: public Item{
private:
public:
    void clicar();
    Type_i tipo(){return Type_i::CARTA;}
};
class I_Din: public Item{
private:
    int valor;
public:
    void clicar();
    int get_valor();
    Type_i tipo(){return Type_i::DINHEIRO;}
};

vector<I_Din *> dinheiro_init;
vector<int> tab_seq;

class Jogador {
private:
    string nome;
    int ordem;
    int dinheiro = 0;
    int id;
    int posicao_tab;
    int posicao_casa = 0;
    bool preso = false;
    bool sua_vez = false;
    vector<Item *> iventario;
public:
    Jogador(string nome_, int tab_init) {
        nome = nome_;
        iventario.assign(dinheiro_init.begin(),dinheiro_init.end());
        for (unsigned i=0; i<iventario.size(); ++i){
            if (iventario[i]->tipo() == Item::Type_i::DINHEIRO)
                dinheiro += iventario[i]->get_valor();
        }
        posicao_tab = tab_init;
    };
    void jogar_dados();
    void mover_peao(int num);
    void receber_dinheiro(int num);
    void pagar(int num,int id_jog=0);
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
                    mover_cadeia();
                else
                    mover_peao(d1+d2);
            }

        }
        else{
            if (!preso)
                mover_peao(d1+d2);
            break;
        }
        if (repetir == max_rep)
            mover_cadeia();
            d1 = rand() % dice +1;
        d2 = rand() % dice +1;
    }
}
void Jogador::mover_cadeia(){
    preso = true;
}
void Jogador::mover_peao(int num_casas){

}

void Jogador::receber_dinheiro(int num){

}

void Jogador::pagar(int num, int id_jog){

}

class Casa{
private:
    int id;
public:
    typedef enum CasaType{
        PROPRIEDADE,
        SORTE_REVES
    } CasaType;
    typedef enum Cor_t {
        BRANCO,
        AZUL
    } Cor_t;
    virtual void Cair() = 0;
    virtual Casa::CasaType tipo() = 0;
    virtual Cor_t get_cor() = 0;

};
class Propriedade: public Casa{
public:
    typedef enum P_type {
        PADRAO,
        CIA,
        USINA
    } P_Type;

private:
    int preco;
    vector<int> aluguel;
    int num_estacoes;
    int hipoteca;
    string nome;
    Cor_t cor;
    P_Type tipo_p;
    Jogador dono;
public:
    CasaType tipo() { return CasaType::PROPRIEDADE; }
    Cor_t get_cor();
};

class Tabuleiro{
private:
    int id;
    vector<Casa *> casas;
    map<Casa::Cor_t, pair<int,int>>  status;
public:
    Tabuleiro(vector<Casa *> casas_){
        casas = casas_;
        for(unsigned i=0;i <  casas.size(); i++){
            if (casas[i]->tipo() == Casa::CasaType::PROPRIEDADE){
                status[casas[i]->get_cor()].first = 1 + status[casas[i]->get_cor()].first;
                status[casas[i]->get_cor()].second = 0;
            }
        }
    }
    pair<int, int> verificar_status(Casa::Cor_t cor){
        return status[cor];
    }
};



class Carta{
protected:
    string nome;
public:
    virtual void acao() = 0;
};

class Baralho{
private:
    vector<Carta *> cartas;
    int pos;
public:
    void embaralhar();
    void puxar_carta(int jogador);
};

class Sorte_Reves: public Casa{
private:
    Baralho s_r;
public:
    CasaType tipo() { return CasaType::SORTE_REVES; }
    void Cair();
};

void Sorte_Reves::Cair(){

};



class Base: public Carta{
public:
    typedef enum c_type{
        DINHEIRO,
        CASA
    }c_type;
private:
    c_type tipo;
    int quant;
public:
    Base(c_type tipo_, int quant_, string nome_){
        tipo = tipo_;
        quant = quant_;
        nome = nome_;
    }
    void acao(int jogador);
};
void Base::acao(int jogador){

};

int main(int argc, char *argv[])
{
    srand(time(NULL));
    dice = 6;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
