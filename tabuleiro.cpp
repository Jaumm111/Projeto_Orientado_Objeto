#include "tabuleiro.h"

void Tabuleiro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(this->rect());
    int casas_p_lado = casas.size()/4;
    int x;
    int y;
    for(int i = 0; i < casas.size() ;i++){
        painter->setBrush(Qt::white);
        if(i/casas_p_lado == 0){
            y = this->rect().height()-(i % casas_p_lado+1)*this->rect().height()/(casas_p_lado+1);
            x = 0;
        }
        else if(i/casas_p_lado == 1){
            y = 0;
            x = (i % casas_p_lado)*this->rect().width()/(casas_p_lado+1);
        }
        else if(i/casas_p_lado == 2){
            y = (i % casas_p_lado)*this->rect().height()/(casas_p_lado+1);
            x = (casas_p_lado)*this->rect().width()/(casas_p_lado+1);
        }
        else if(i/casas_p_lado == 3){
            y = (casas_p_lado)*this->rect().height()/(casas_p_lado+1);
            x = this->rect().width()-(i % casas_p_lado+1)*this->rect().width()/(casas_p_lado+1);
        }
        if(i%casas_p_lado==0){
            painter->setBrush(QColor(casas[i]->get_cor()));
        }
        painter->setBrush(Qt::white);
        painter->drawRect(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1));
        painter->setBrush(QColor(casas[i]->get_cor()));
        painter->drawRect(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1)/5);
        QFont font = painter->font() ;

        /* twice the size than the current font size */
        font.setPointSize(7);
        painter->setFont(font);
        painter->drawText(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1),Qt::AlignCenter|Qt::TextWordWrap,casas[i]->getNome(),new QRect(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1)));
        if(casas[i]->getPreco() > 0){
            painter->drawText(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1),Qt::AlignBottom|Qt::AlignHCenter|Qt::TextWordWrap,QString::number(casas[i]->getPreco()),new QRect(x,y,this->rect().width()/(casas_p_lado+1),this->rect().height()/(casas_p_lado+1)));
        }
    }
}

Tabuleiro::Tabuleiro(vector<Casa *> casas_, qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent)
{
    casas = casas_;
    qDebug() << casas_.size();
    tam = casas_.size();
    for(unsigned i=0;i <  casas.size(); i++){
        if (casas[i]->tipo() == Casa::CasaType::PROPRIEDADE){
            status[casas[i]->get_cor()].first = 1 + status[casas[i]->get_cor()].first;
            status[casas[i]->get_cor()].second = 0;
        }
    }
}

pair<int, int> Tabuleiro::verificar_status(QString cor){
    return status[cor];
}

int Tabuleiro::getCadeia(){
    for(int i=0;i<casas.size();i++){
        if(casas[i]->getNome()=="Cadeia"){
            return i;
        }
    }
    return 0;
}

void Tabuleiro::cair(int pos, Jogador * jogador){
    //casas[pos]->cair();
    qDebug() << pos;
    qDebug() << "teste";
    int casas_p_lado = casas.size()/4;
    int x = 0;
    int y = 0;
    if(pos/casas_p_lado == 0){
        y = this->rect().height()-(pos % casas_p_lado+1)*this->rect().height()/(casas_p_lado+1);
        x = 0;
    }
    else if(pos/casas_p_lado == 1){
        y = 0;
        x = (pos % casas_p_lado)*this->rect().width()/(casas_p_lado+1);
    }
    else if(pos/casas_p_lado == 2){
        y = (pos % casas_p_lado)*this->rect().height()/(casas_p_lado+1);
        x = (casas_p_lado)*this->rect().width()/(casas_p_lado+1);
    }
    else if(pos/casas_p_lado == 3){
        y = (casas_p_lado)*this->rect().height()/(casas_p_lado+1);
        x = this->rect().width()-(pos % casas_p_lado+1)*this->rect().width()/(casas_p_lado+1);
    }
    jogador->setPos((this->x()+x+this->rect().width()/(casas_p_lado+1)/2),(this->y()+y+this->rect().height()/(casas_p_lado+1)/2));
}
