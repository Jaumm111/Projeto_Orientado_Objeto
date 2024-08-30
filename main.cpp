

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <stdlib.h>

#include <QApplication>
#include <QtWidgets>

using namespace std;
#include "carddisplay.h"
#include "casa.h"
#include "tabuleiro.h"
#include "item.h"

#include "mainwindow.h"



class Jogador;


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
    Config::Game::getInstance()->set_dice(6);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
