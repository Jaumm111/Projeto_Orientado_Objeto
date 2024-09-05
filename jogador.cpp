#include "jogador.h"

Jogador::Jogador(QString nome_,
                 JogoScene * s,
                 qreal x, qreal y,
                 qreal width, qreal height,
                 QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent){
    nome = nome_;
    scene = s;
    posicao_tab = 0;
    dinheiro = 0;
    qDebug() << "iventario";
    qDebug() << Config::Game::getInstance()->get_d_init().size();
    int posx = -100;
    int posy = -100;
    for(int i =0 ; i < Config::Game::getInstance()->get_d_init().size();i++){
        CardDisplay *d= new CardDisplay(Config::Game::getInstance()->get_d_init()[i].getItem());
        iventario.push_back(new I_Din(Config::Game::getInstance()->get_d_init()[i].get_valor(),d));
        iventario[i]->getItem()->setPos(posx,posy);
        posx += iventario[i]->getItem()->rect().width();
        scene->addItem(iventario[i]->getItem());
    }
    qDebug() << iventario.size();
    for (unsigned i=0; i<iventario.size(); i++){
        qDebug() << i;
        if (iventario[i]->tipo() == Item::Type_i::DINHEIRO)
            dinheiro += iventario[i]->get_valor();
    }
}

void Jogador::itemVisible(bool v){
    for (unsigned i=0; i<iventario.size(); i++){
        iventario[i]->setVisible(v);
    }
}
void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(this->rect());
    painter->setPen(Qt::white);
    QFont font = painter->font() ;

    /* twice the size than the current font size */
    font.setPointSize(7);

    /* set the modified font to the painter */
    painter->setFont(font);
    painter->drawText(this->rect(),Qt::AlignCenter,nome);

}
void Jogador::jogar_dados(JogoScene * scene){
    int d1;
    int d2;
    int repetir = 0;
    qDebug()<<"dados";
    if (preso){
        d1 = rand() % 6 +1;
        d2 = rand() % 6 +1;
    }
    else{
        d1 = rand() % Config::Game::getInstance()->get_dice() +1;
        d2 = rand() % Config::Game::getInstance()->get_dice() +1;
    }
    qDebug() << repetir;
    qDebug() << Config::Game::getInstance()->get_max_rep();
    while (repetir < Config::Game::getInstance()->get_max_rep()){
        qDebug() << this->getNome();
        qDebug() << d1;
        qDebug() << d2;
        if (d1 == d2){
            qDebug()<<"IGUAIS";
            repetir++;
            if (preso){
                repetir--;
                preso=false;
            }
            else{
                if (repetir == Config::Game::getInstance()->get_max_rep())
                    mover_cadeia();
                else
                    qDebug() << "mover";
                    mover_peao(d1+d2);
            }

        }
        else{
            if (!preso)
                qDebug() << "mover";
                mover_peao(d1+d2);
            break;
        }
        if (repetir == Config::Game::getInstance()->get_max_rep())
            mover_cadeia();
        d1 = rand() % Config::Game::getInstance()->get_dice() +1;
        d2 = rand() % Config::Game::getInstance()->get_dice() +1;
    }
    qDebug() << "prox";
    scene->nextJog();
}
void Jogador::mover_cadeia(){
    preso = true;
    int tam = Config::Game::getInstance()->get_tab()[posicao_tab]->getTam();
    int casas = Config::Game::getInstance()->get_tab()[posicao_tab]->getCadeia();
    if ((posicao_casa >= tam/2) && (casas < tam/2)){
        if (posicao_tab!= 0){
            posicao_tab = (posicao_tab-1)%Config::Game::getInstance()->get_tab().size();
        }
        else{
            posicao_tab = Config::Game::getInstance()->get_tab().size()-1;
        }
    }
    posicao_casa=casas;
}
void Jogador::mover_peao(int num_casas){
    qDebug()<< posicao_tab;
    qDebug()<< Config::Game::getInstance()->get_tab()[posicao_tab]->getTam();
    int tam = Config::Game::getInstance()->get_tab()[posicao_tab]->getTam();
    qDebug()<< "teste";
    if ((posicao_casa < tam/2) && (posicao_casa+num_casas >= tam/2)){
        qDebug()<< "meio";
        posicao_tab = (posicao_tab+1)%Config::Game::getInstance()->get_tab().size();
    }
    if (posicao_casa+num_casas >= tam){
        qDebug()<< "volta";
        posicao_casa=posicao_casa-tam;
        num_voltas+=1;
        receber_dinheiro(200);
    }
    posicao_casa=posicao_casa+num_casas;

    qDebug() << "movendo";
    Config::Game::getInstance()->get_tab()[posicao_tab]->cair(posicao_casa,this);
}

void Jogador::receber_dinheiro(int num){
    vector<int>::iterator it;
    int rest = num;
    qDebug() << "receber";
    dinheiro += num;
    for (unsigned i=0; i<iventario.size(); i++){
        if (iventario[i]->tipo() == Item::Type_i::DINHEIRO){
            iventario[i]->change(num);
            break;
        }
    }
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
