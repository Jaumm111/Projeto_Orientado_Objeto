#include "item.h"

Item::Item(CardDisplay *a)
{
    imagem = a;
}
void Item::setVisible(bool v){
    imagem->setVisible(v);
}

void Item::setCor(QString cor){imagem->setCor(cor);}

I_Din::I_Din(int valor_, CardDisplay *a) : Item(a)
{
    valor = valor_;
    imagem->addText("$ "+QString::number(valor));
}

void I_Din::change(int i){
    valor+=i;
    imagem->addText("$ "+QString::number(valor));
}

I_Prop::I_Prop(Propriedade *p, CardDisplay *i): Item(i)
{
    prop = p;
}
