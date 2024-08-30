#ifndef CASA_H
#define CASA_H

#include <vector>
#include <string>

using namespace std;

#include "jogador.h"

class Jogador;

class Casa{
private:
    int id;
public:
    Casa();
    typedef enum CasaType{
        PROPRIEDADE,
        SORTE_REVES
    } CasaType;
    virtual void Cair() = 0;
    virtual Casa::CasaType tipo() = 0;
    virtual string get_cor() = 0;

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
    string cor;
    P_Type tipo_p;
    Jogador *dono;
public:
    CasaType tipo() { return CasaType::PROPRIEDADE; }
    string get_cor();
};

#endif // CASA_H
