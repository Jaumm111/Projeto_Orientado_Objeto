#ifndef CASA_H
#define CASA_H

#include <vector>
#include <QString>

using namespace std;

#include "jogador.h"
#include "baralho.h"

class Baralho;
class I_Prop;
class Jogador;
class Comprar;

class Casa{
private:
    int id;
protected:
    QString nome;
public:
    QString getNome(){return nome;}
    Casa(QString nome_);
    typedef enum CasaType{
        CANTO,
        PROPRIEDADE,
        SORTE_REVES,
        VPP
    } CasaType;
    virtual void cair(Jogador * jog){ };
    virtual int getPreco(){return 0;}
    virtual Casa::CasaType tipo(){return CasaType::CANTO;};
    virtual QString get_cor(){return "gray";};

};
class Propriedade: public Casa{
public:
    typedef enum P_Type {
        PADRAO,
        CIA,
        USINA
    } P_Type;

private:
    int preco;
    vector<int> aluguel;
    int num_estacoes;
    int hipoteca;
    int peso;
    QString cor;
    P_Type tipo_p;
    Jogador *dono;
    I_Prop *carta;
    Comprar * c;
    Comprar * p;
    bool espera;
public:
    Propriedade(QString nome_,QString c,int preco_,int hipoteca_,int peso_,int t,vector<int> v_aluguel);
    CasaType tipo() { return CasaType::PROPRIEDADE; }
    QString get_cor(){return cor;}
    int getPreco(){return preco;}
    I_Prop * getCarta(){return carta;}
    void comprar(Jogador *j);
    void esperado(Jogador *j);
    void cair(Jogador * jog);
};
class Prender: public Casa{
public:
    Prender(QString nome_): Casa(nome_) { }
    CasaType tipo() { return CasaType::VPP; }
    void cair(Jogador * jog);
    QString get_cor(){return "gray";};

};
class Sorte_Reves: public Casa{
private:
    Baralho *s_r;
public:
    Sorte_Reves(QString nome_="Sorte_Reves"): Casa(nome_) { }
    CasaType tipo() { return CasaType::SORTE_REVES; }
    void cair(Jogador * jog);
    QString get_cor(){return "gray";};
};

#endif // CASA_H
