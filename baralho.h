#ifndef BARALHO_H
#define BARALHO_H
#include "casa.h"
using namespace std;

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
    Baralho();
    void embaralhar();
    void puxar_carta(int jogador);
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
#endif // BARALHO_H
