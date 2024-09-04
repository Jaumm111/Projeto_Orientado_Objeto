

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
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
