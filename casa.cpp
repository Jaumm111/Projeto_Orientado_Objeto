#include "casa.h"

Casa::Casa(QString nome_)
{
    nome = nome_;
}

Propriedade::Propriedade(QString nome_,
                         QString c,
                         int preco_,
                         int hipoteca_,
                         int peso_,
                         int t,
                         vector<int> v_aluguel): Casa(nome_)
{
    preco = preco_;
    hipoteca = hipoteca_;
    peso = peso_;
    if(t == 0){
        tipo_p = P_Type::PADRAO;
    }
    else if(t == 1){
        tipo_p = P_Type::CIA;
    }
    else if(t == 2){
        tipo_p = P_Type::USINA;
    }
    cor = c;
    aluguel = v_aluguel;
    CardDisplay *a = new CardDisplay(0,0,60,80);
    QString escrever = nome+"\n";
    for(int i = 0;i<aluguel.size();i++){
        escrever+="\n"+QString::number(aluguel[i]);
    }
    a->addText(escrever);
    carta = new I_Prop(this,a);
}

void Prender::cair(Jogador * jog){
    jog->mover_cadeia();
}
void Propriedade::cair(Jogador * jog)
{

}
void Sorte_Reves::cair(Jogador * jog)
{

}
