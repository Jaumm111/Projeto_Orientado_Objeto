#ifndef CONFIG_SCENE_H
#define CONFIG_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QCursor>

class configScene : public QGraphicsScene
{
public:
    explicit configScene(QObject *parent = nullptr);

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
    QPushButton     * pbutton2;
    QCursor         * cursor;
    QGraphicsLineItem * x_axis;
    QGraphicsLineItem * y_axis;

};

#endif // CONFIG_SCENE_H
