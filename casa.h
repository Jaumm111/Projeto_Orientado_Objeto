#ifndef CASA_H
#define CASA_H

#include <vector>
#include <string>

using namespace std;

#include "jogador.h"
#include "baralho.h"
class Baralho;
class Jogador;

class Casa{
private:
    int id;
protected:
    string nome;
public:
    Casa(string nome_);
    typedef enum CasaType{
        PROPRIEDADE,
        SORTE_REVES,
        VPP
    } CasaType;
    virtual void Cair() {}
    string getNome(){return nome;}
    virtual Casa::CasaType tipo() { }
    virtual string get_cor() { return ""; }

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
    string cor;
    int peso;
    P_Type tipo_p;
    Jogador *dono;
public:
    Propriedade(string nome_,string c,int preco_,int hipoteca,int peso_,int t,vector<int> v_aluguel);
    CasaType tipo() { return CasaType::PROPRIEDADE; }
    string get_cor();
    void Cair();
};
class Prender: public Casa{
public:
    Prender(string nome_): Casa(nome_) { }
    CasaType tipo() { return CasaType::VPP; }
    void Cair();
};
class Sorte_Reves: public Casa{
private:
    Baralho *s_r;
public:
    Sorte_Reves(string nome_="Sorte_Reves"): Casa(nome_) { }
    CasaType tipo() { return CasaType::SORTE_REVES; }
    void Cair();
};
#endif // CASA_H
