#include "carddisplay.h"
#include <QDebug>

CardDisplay::CardDisplay(const QPixmap &pixmap,
                         QGraphicsItem *parent) : QGraphicsPixmapItem(pixmap, parent)
{

}

void CardDisplay::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Card clicked !!!";
    //this->setVisible(!this->isVisible());
}
