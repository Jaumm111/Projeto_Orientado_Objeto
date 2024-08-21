#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QCursor>

class menuScene : public QGraphicsScene
{
public:
    explicit menuScene(QObject *parent = nullptr);

    void setAxis(bool value);


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void open();
private:

    QTimer          * _timer;
    QPushButton     * pbutton;
    QCursor         * cursor;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;

};

#endif // MENU_SCENE_H
