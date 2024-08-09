#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>

class menuScene : public QGraphicsScene
{
public:
    explicit menuScene(QObject *parent = nullptr);

    void setAxis(bool value);


    // QGraphicsScene interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:

    QTimer          * _timer;
    QPushButton     * pbutton;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;

};

#endif // MENU_SCENE_H
