#include "tabuleiro.h"

Tabuleiro::Tabuleiro(vector<Casa *> casas_){
    casas = casas_;
    for(unsigned i=0;i <  casas.size(); i++){
        if (casas[i]->tipo() == Casa::CasaType::PROPRIEDADE){
            status[casas[i]->get_cor()].first = 1 + status[casas[i]->get_cor()].first;
            status[casas[i]->get_cor()].second = 0;
        }
    }
}
pair<int, int> Tabuleiro::verificar_status(string cor){
    return status[cor];
}

int Tabuleiro::getCadeia(){
    for(int i=0;i<casas.size();i++){
        if(casas[i]->getNome()=="Cadeia"){
            return i;
        }
    }
}


void Tabuleiro::cair(int pos){
    casas[pos]->Cair();
}
