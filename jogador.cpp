#include "jogador.h"

Jogador::Jogador(string nome_, int tab_init) {
    nome = nome_;
    iventario.assign(dinheiro_init.begin(),dinheiro_init.end());
    for (unsigned i=0; i<iventario.size(); ++i){
        if (iventario[i]->tipo() == Item::Type_i::DINHEIRO)
            dinheiro += iventario[i]->get_valor();
    }
    posicao_tab = tab_init;
}

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
    int tam = tab[posicao_tab]->getTam();
    if ((posicao_casa < tam/2) && (posicao_casa+num_casas >= tam/2)){
        posicao_tab = (posicao_tab+1)%tab.size();
    }
    if (posicao_casa+num_casas >= tam){
        posicao_casa=posicao_casa-tam;
        num_voltas+=1;
    }
    posicao_casa=posicao_casa+num_casas;
}

void Jogador::receber_dinheiro(int num){
    vector<int>::iterator it;
    int rest = num;
    //   while(rest > 0 ){
    //        for( it = notas.begin() ; it != notas.end(); ++it){
    //          if (rest > *it){
    //iventario.insert(I_Din(*it))
    //        }
    //  }
    // }
}

void Jogador::pagar(int num, int id_jog){

}
