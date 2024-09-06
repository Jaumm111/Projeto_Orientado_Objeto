#include "jogador.h"

Jogador::Jogador(QString nome_,
                 QString cor_,
                 JogoScene * s,
                 qreal x, qreal y,
                 qreal width, qreal height,
                 QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent){
    nome = nome_;
    scene = s;
    posicao_tab = 0;
    dinheiro = 0;
    cor = cor_;
    x_ = 50;
    y_ = -200;
    int posx = -100;
    int posy = -100;
    for(int i =0 ; i < Config::Game::getInstance()->get_d_init().size();i++){
        CardDisplay *d= new CardDisplay(Config::Game::getInstance()->get_d_init()[i].getItem());
        iventario.push_back(new I_Din(Config::Game::getInstance()->get_d_init()[i].get_valor(),d));
        iventario[i]->getItem()->setPos(posx,posy);
        iventario[i]->getItem()->setCor(cor);
        posx += iventario[i]->getItem()->rect().width();
        scene->addItem(iventario[i]->getItem());
    }
    for (unsigned i=0; i<iventario.size(); i++){
        qDebug() << i;
        if (iventario[i]->tipo() == Item::Type_i::DINHEIRO)
            dinheiro += iventario[i]->get_valor();
    }
}

void Jogador::add_item(Item * i){
    iventario.push_back(i);
    iventario.back()->getItem()->setPos(x_,y_);
    scene->addItem(iventario.back()->getItem());
    if(x_+120>Config::Viewport::WIDTH*0.5){
        x_ = 50;
        y_ +=80;
    }
    else
        x_+=60;
}

void Jogador::itemVisible(bool v){
    for (unsigned i=0; i<iventario.size(); i++){
        iventario[i]->setVisible(v);
    }
}
void Jogador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(cor));
    painter->drawRect(this->rect());
    painter->setPen(Qt::white);
    QFont font = painter->font() ;

    /* twice the size than the current font size */
    font.setPointSize(7);

    /* set the modified font to the painter */
    painter->setFont(font);
    painter->drawText(this->rect(),Qt::AlignCenter,nome);

}
void Jogador::jogar_dados(){
    int d1;
    int d2;
    qDebug()<<"dados";
    if (preso){
        d1 = rand() % 6 +1;
        d2 = rand() % 6 +1;
    }
    else{
        d1 = rand() % Config::Game::getInstance()->get_dice() +1;
        d2 = rand() % Config::Game::getInstance()->get_dice() +1;
    }
    scene->setDados(d1,d2);
    if (repetir < Config::Game::getInstance()->get_max_rep()){
        if (d1 == d2){
            qDebug()<<"IGUAIS";
            repetir++;
            if (preso){
                repetir=0;
                preso=false;
            }
            else{
                if (repetir == Config::Game::getInstance()->get_max_rep()){
                    qDebug() << "Cadeia";
                    mover_cadeia();
                    repetir = 0;
                }
                else{
                    qDebug() << "mover";
                    denovo = true;
                    mover_peao(d1+d2);
                }
            }

        }
        else{
            denovo = false;
            if (!preso){
                qDebug() << "mover";
                mover_peao(d1+d2);
                repetir = 0;
            }
            else{
                qDebug() << "prox";
                scene->nextJog();
                repetir++;
                if(repetir == Config::Game::getInstance()->get_max_rep()){
                    preso = false;
                    repetir =0;
                }
            }
        }
    }
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
    Config::Game::getInstance()->get_tab()[posicao_tab]->cair(posicao_casa,this);
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

void Jogador::pagar(int num, Jogador * j){
    dinheiro -= num;
    for (unsigned i=0; i<iventario.size(); i++){
        if (iventario[i]->tipo() == Item::Type_i::DINHEIRO){
            iventario[i]->change(-num);
            break;
        }
    }
    if(j!= nullptr){
        j->receber_dinheiro(num);
    }
}
