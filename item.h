#ifndef ITEM_H
#define ITEM_H

#include "carddisplay.h"
#include "casa.h"

class CardDisplay;
class Propriedade;

class Item{
protected:
    CardDisplay *imagem;
public:
    Item(CardDisplay *a);
    typedef enum Type_i{
        PROPRIEDADE,
        CARTA,
        DINHEIRO
    }Type_i;
    void setVisible(bool v);
    CardDisplay * getItem(){return imagem;}
    void clicar();
    void setCor(QString cor);
    virtual int get_valor() = 0;
    virtual void change(int i) =0;
    virtual Type_i tipo() = 0;
};
class I_Prop: public Item{
private:
    Propriedade * prop;
public:
    I_Prop(Propriedade * p,CardDisplay *i);
    void clicar();
    Type_i tipo(){return Type_i::PROPRIEDADE;}
    int get_valor(){return 0;}
    void change(int i){}
};
class I_Carta: public Item{
private:
public:
    I_Carta(CardDisplay * a) : Item(a){}
    void clicar();
    Type_i tipo(){return Type_i::CARTA;}
    int get_valor(){return 0;}
    void change(int i){}
};
class I_Din: public Item{
private:
    int valor;
public:
    I_Din(int valor_,CardDisplay *a);
    void clicar();
    void change(int i);
    int get_valor(){return valor;}
    Type_i tipo(){return Type_i::DINHEIRO;}
};
#endif // ITEM_H
