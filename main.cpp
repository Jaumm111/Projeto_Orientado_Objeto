

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <stdlib.h>

#include <QApplication>
#include <QtWidgets>

using namespace std;
#include "carddisplay.h"
#include "casa.h"
#include "tabuleiro.h"
#include "item.h"

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));
    Config::Game::getInstance()->set_dice(6);
    Config::Game::getInstance()->set_max_rep(2);
    Config::Game::getInstance()->set_d_init(vector<I_Din>({I_Din(1800,new CardDisplay(0,0,100,50))}));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
