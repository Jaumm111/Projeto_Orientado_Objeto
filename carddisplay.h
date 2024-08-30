#ifndef CARDDISPLAY_H
#define CARDDISPLAY_H

#include <QGraphicsRectItem>

class CardDisplay : public QGraphicsPixmapItem
{
public:
    CardDisplay(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CARDDISPLAY_H
