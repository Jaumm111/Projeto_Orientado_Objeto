#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <map>
#include <QGraphicsRectItem>
#include <QString>
#include <QColor>
#include <QBrush>

#include "casa.h"
#include "jogador.h"
class Casa;
class Jogador;


using namespace std;

class Tabuleiro: public QGraphicsRectItem{
private:
    int id;
    int tam;
    vector<Casa *> casas;
    map<QString, pair<int,int>>  status;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
public:
    Tabuleiro(vector<Casa *> casas_,qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    pair<int, int> verificar_status(QString cor);
    int getTam(){return tam;}
    int getCadeia();
    void cair(int pos,Jogador * jogador);
};

#endif // TABULEIRO_H
