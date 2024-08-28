#ifndef CONFIG_H
#define CONFIG_H

#include <QtMath>

#include <vector>
#include <string>

using namespace std;

#include "item.h"
#include "casa.h"
#include "jogador.h"
#include "tabuleiro.h"

namespace Config {

namespace Viewport {
    const int WIDTH = 600;
    const int HEIGHT = 600;
    const int FPS = 33;
};
    }
class Config_main{
private:
    vector<I_Din *> dinheiro_init;
    //vector<int> notas(500,100,50,20,10,5,1);
    vector<Tabuleiro *> tab;
    vector<int> tab_seq;
};

#endif // CONFIG_H
