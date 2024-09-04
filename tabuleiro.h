#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <map>

#include "casa.h"
class Casa;


using namespace std;

class Tabuleiro{
private:
    int id;
    vector<Casa *> casas;
    map<string, pair<int,int>>  status;
public:
    Tabuleiro(vector<Casa *> casas_);
    pair<int, int> verificar_status(string cor);
    int getTam(){return casas.size();}
    int getCadeia();
    void cair(int pos);
};

#endif // TABULEIRO_H
