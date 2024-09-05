#include "botao.h"

#include <QDebug>
#include <QPainter>

Botao::Botao(qreal x, qreal y,
                         qreal width, qreal height,
                         QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent)
{

}

void Botao::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRoundedRect(this->rect(),6,6);
    painter->setPen(Qt::white);
    QFont font = painter->font() ;

    /* twice the size than the current font size */
    font.setPointSize(15);
    font.setStyleHint(QFont::Cursive);

    /* set the modified font to the painter */
    painter->setFont(font);
    painter->drawText(this->rect(),Qt::AlignCenter,nome);

}
void Botao::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Card clicked !!!";
    window->changeScene(scene);
    //this->setVisible(!this->isVisible());
}

Util_b::Util_b(qreal x, qreal y,
                         qreal width, qreal height,
                         QGraphicsItem *parent) : Botao(x,y,width,height, parent){}
void Util_b::setScene(JogoScene * j){
    scene = j;
}
void Util_b::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug() << "botao";
    jogador->jogar_dados(scene);
}
void Util_b::setAtual(Jogador *j) {
    qDebug() << j->getNome();
    jogador = j;
}
