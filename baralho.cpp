#include "baralho.h"


Base::Base(c_type tipo_, int quant_, QString nome_){
    tipo = tipo_;
    quant = quant_;
    nome = nome_;

    CardDisplay *a = new CardDisplay(0,0,60,80);
    QString escrever = nome+"\n"+QString::number(quant);
    qDebug()<<escrever;
    a->addText(escrever);
    a->setCor("gray");
    a->setPos(-30,-230);
    carta = new I_Carta(a);
}
void Base::acao(Jogador *j){
    if(tipo == c_type::DINHEIRO){
        j->receber_dinheiro(quant);
    }
    else if(tipo == c_type::CASA){
        j->mover_peao(quant);
    }
}

Baralho::Baralho(vector<Carta *> c){
    cartas = c;
    pos = 0;
    embaralhar();
}

void Baralho::embaralhar()
{
    vector<Carta *> c;
    for(int i=0;i<cartas.size();i++){
        int a = rand()%(1+i);
        c.insert(c.begin()+a,cartas[i]);
    }
    cartas = c;
}
Carta * Baralho::puxar_carta(Jogador * j){
    cartas[pos]->acao(j);
    Carta * c= cartas[pos];
    pos++;
    if(pos >= cartas.size()){
        pos = 0;
        embaralhar();
    }
    return c;
}
