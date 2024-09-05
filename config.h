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

class Tabuleiro;
class I_Din;



namespace Config {

    namespace Viewport {
        const int WIDTH = 800;
        const int HEIGHT = 800;
        const int FPS = 33;
    };

    class Game{
        private:
            Game();
            vector<I_Din> dinheiro_init;
            //vector<int> notas;//(500,100,50,20,10,5,1);
            vector<Tabuleiro *> tab;
            vector<int> tab_seq;
            int dice;
            int max_rep;

            static Game *instance;

        public:
            vector<I_Din> get_d_init(){return dinheiro_init;}
            vector<Tabuleiro *> get_tab(){return tab;}
            vector<int> get_tab_seq(){return tab_seq;}
            int get_dice(){return dice;}
            int get_max_rep(){return max_rep;}
            void set_d_init(vector<I_Din> dinheiro_init_){dinheiro_init = dinheiro_init_;}
            void set_tab(vector<Tabuleiro *> tab_){tab =tab_;}
            void set_tab_seq(vector<int> tab_seq_){tab_seq = tab_seq_;}
            void set_dice(int dice_){dice = dice_;}
            void set_max_rep(int max_rep_){max_rep = max_rep_;}

            static Game * getInstance();

    };

}

#endif // CONFIG_H
