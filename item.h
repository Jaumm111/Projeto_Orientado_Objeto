#ifndef ITEM_H
#define ITEM_H

#include "carddisplay.h"
#include "casa.h"

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
    void clicar();
    virtual int get_valor() = 0;
    virtual Type_i tipo() = 0;
};
class I_Prop: public Item{
private:
    Propriedade * prop;
public:
    void clicar();
    Type_i tipo(){return Type_i::PROPRIEDADE;}
};
class I_Carta: public Item{
private:
public:
    void clicar();
    Type_i tipo(){return Type_i::CARTA;}
};
class I_Din: public Item{
private:
    int valor;
public:
    I_Din(int valor);
    void clicar();
    int get_valor();
    Type_i tipo(){return Type_i::DINHEIRO;}
};
#endif // ITEM_H
