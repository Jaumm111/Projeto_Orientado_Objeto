#include "carddisplay.h"
#include <QDebug>

CardDisplay::CardDisplay(qreal x, qreal y,
                         qreal width, qreal height,
                         QGraphicsItem *parent) : QGraphicsRectItem(x,y,width,height, parent)
{

}

void CardDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Card clicked !!!";
    //this->setVisible(!this->isVisible());
}
