#ifndef BOTAO_H
#define BOTAO_H

#include <QGraphicsRectItem>
#include "mainwindow.h"
#include "jogador.h"
class Jogador;
class MainWindow;
class JogoScene;

using namespace std;

class Botao : public QGraphicsRectItem
{
public:
    Botao(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void addPixMap(QPixmap map_){map=map_;}
    void set_Scene(int sc){scene=sc;}
    void setText(QString nome_){nome=nome_;}
    void set_Window(MainWindow * window_){window=window_;}

    // QGraphicsItem interface
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QPixmap map;
    int scene;
    QString nome;
    MainWindow * window;
};

class Util_b: public Botao{
public:
    Util_b(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void setAtual(Jogador *j);
    void setScene(JogoScene * j);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    Jogador * jogador;
    JogoScene * scene;
};


#endif // BOTAO_H
