#ifndef BARALHO_H
#define BARALHO_H
#include "casa.h"
#include "item.h"
class I_Carta;
using namespace std;
class Jogador;

class Carta{
protected:
    QString nome;
    I_Carta * carta;
public:
    virtual void acao(Jogador *j) = 0;
    virtual I_Carta * getC() = 0;
};
class Baralho{
private:
    vector<Carta *> cartas;
    int pos;
public:
    Baralho(vector<Carta *> c);
    void embaralhar();
    Carta * puxar_carta(Jogador *j);
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
    Base(c_type tipo_, int quant_, QString nome_);
    I_Carta * getC(){return carta;}
    void acao(Jogador *j);
};
#endif // BARALHO_H
