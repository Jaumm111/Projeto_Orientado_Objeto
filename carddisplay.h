#ifndef CARDDISPLAY_H
#define CARDDISPLAY_H

#include <QGraphicsRectItem>
#include "mainwindow.h"

class MainWindow;

class CardDisplay : public QGraphicsRectItem
{
public:
    CardDisplay(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    CardDisplay(CardDisplay *d);
    //void addPixMap(QPixmap map_){map=map_;}
    void addText(QString s){texto = s;}
    void setCor(QString s){cor = s;}
    void setCursor(QCursor * cursor_){cursor=cursor_;}
    void set_Window(MainWindow * window_,QPoint lim_){window=window_;lim=lim_;}

    // QGraphicsItem interface
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QPoint lim;
    QString cor;
    QString texto;
    QCursor * cursor;
    MainWindow * window;
};

#endif // CARDDISPLAY_H
