#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <map>

#include "casa.h"



using namespace std;

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
    int getTam(){return casas.size();}
    void cair(int pos){casas[pos]->Cair();}
};

#endif // TABULEIRO_H
