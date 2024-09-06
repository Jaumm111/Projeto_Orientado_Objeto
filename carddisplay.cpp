#include "carddisplay.h"
#include <QDebug>
#include <QPainter>
#include <QCursor>

CardDisplay::CardDisplay(qreal x, qreal y,
                         qreal width, qreal height,
                         QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent)
{
}
CardDisplay::CardDisplay(CardDisplay *d) : QGraphicsRectItem(d->rect())
{

}
void CardDisplay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(cor));
    painter->drawRoundedRect(this->rect(),5,5);
    painter->setBrush(Qt::white);
    painter->drawRoundedRect(this->rect().width()*0.05,
                             this->rect().height()*0.05,
                             this->rect().width()*0.9,
                             this->rect().height()*0.9,5,5);
    //painter->drawPixmap(this->rect().toAlignedRect(),map);
    QFont font = painter->font() ;

    /* twice the size than the current font size */
    font.setPointSize(7);
    painter->setFont(font);
    painter->drawText(this->rect().width()/20,
                      this->rect().height()/20,
                      this->rect().width()*0.9,
                      this->rect().height()*0.9,
                      Qt::AlignCenter|Qt::TextWordWrap,
                      texto,
                      new QRect(this->rect().width()*0.05,
                                this->rect().height()*0.05,
                                this->rect().width()*0.9,
                                this->rect().height()*0.9));


}
void CardDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Card clicked !!!";
}
