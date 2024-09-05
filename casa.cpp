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
    dono = nullptr;
    num_estacoes = 0;
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
    qDebug()<<escrever;
    a->addText(escrever);
    a->setCor(cor);
    carta = new I_Prop(this,a);
}

void Propriedade::comprar(Jogador *j)
{
    dono = j;
    dono->pagar(preco);
    dono->add_item(carta);
}

void Propriedade::esperado(Jogador *j){
    espera = false;
    delete p;
    delete c;
    j->getScene()->setEspera(espera);
}

void Prender::cair(Jogador * jog){
    jog->mover_cadeia();
    jog->getScene()->nextJog();
}
void Propriedade::cair(Jogador * jog)
{
    espera = true;
    while(espera){
        if(dono == nullptr){
            c= new Comprar(0,0,100,50);
            c->setProp(this);
            c->setAtual(jog);
            c->setScene(jog->getScene());
            c->setText("Comprar");
            c->setPos(-0.5*Config::Viewport::WIDTH*0.7,
                      -0.5*Config::Viewport::HEIGHT*0.9);
            p= new Comprar(0,0,100,50);
            p->setProp(this);
            p->setAtual(jog);
            p->setScene(jog->getScene());
            p->setText("Passar");
            p->setPos(0.5*Config::Viewport::WIDTH*0.7-100,
                      -0.5*Config::Viewport::HEIGHT*0.9);
            jog->getScene()->addItem(c);
            jog->getScene()->addItem(p);
            jog->getScene()->setEspera(espera);
            break;

        }
        else if(dono != jog){
            jog->pagar(aluguel[num_estacoes],dono);
            jog->getScene()->nextJog();
            break;
        }
        else{
            jog->getScene()->nextJog();
            break;
        }
    }
}
void Sorte_Reves::cair(Jogador * jog)
{
    jog->getScene()->nextJog();
}
