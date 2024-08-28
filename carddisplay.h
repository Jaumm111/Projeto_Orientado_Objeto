#ifndef CARDDISPLAY_H
#define CARDDISPLAY_H

#include <QGraphicsRectItem>

class CardDisplay : public QGraphicsRectItem
{
public:
    CardDisplay(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CARDDISPLAY_H
