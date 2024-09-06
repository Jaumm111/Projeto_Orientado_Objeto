#include "jogoscene.h"

#include "config.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPushButton>
#include <QFile>
#include <QStringList>

using namespace std;

JogoScene::JogoScene(QObject *parent)
    : QGraphicsScene{parent}
{

    window = dynamic_cast<MainWindow*>(parent);

    setSceneRect(-0.5*Config::Viewport::WIDTH,
                 -0.5*Config::Viewport::HEIGHT,
                 Config::Viewport::WIDTH,
                 Config::Viewport::HEIGHT);

    // Construct Scene Axis -----------------------
    int x_limit = (0.5 * width())+12;
    int y_limit = (0.5 * height())+12;
    lim = QPoint(x_limit,y_limit);
    x_axis = addLine(-x_limit,0,x_limit,0);
    x_axis->setZValue(10);
    y_axis = addLine(0,-y_limit,0,y_limit);
    y_axis->setZValue(10);
    setAxis(false);
    // --------------------------------------------
    getBaralho(":/SorteReves.csv");
    getTab(":/tab.csv");

    //setBackgroundBrush(QBrush(QColor(QColorConstants::Svg::lightsteelblue)));
    cursor = new QCursor();
    cursor->setShape(Qt::CrossCursor);
    qDebug() << "botao";
    pbutton = new Botao(0,0,100,50);
    pbutton->setPos(-x_limit*.7,y_limit*.9-50);
    pbutton->setText("Config");
    pbutton->addPixMap(QPixmap(":/images/botao.jfif"));
    pbutton->set_Window(window);
    pbutton->set_Scene(1);
    addItem(pbutton);
    qDebug() << "botaofim";
    vector<Jogador *> j;
    QFile file(":/jogadores.csv");

    qDebug() << "jogador";
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line = line.split(';').first();
        qDebug() << line;
        j.push_back(new Jogador(line.split(',')[0],line.split(',')[1],this));
        qDebug() << "Criado";
    }
    qDebug() << "Aleatorizar jogadores";
    for(int i=0;i<j.size();i++){
        int a = rand()%(1+i);
        j[i]->setPos(-10,0);
        addItem(j[i]);
        jog.insert(jog.begin()+a,j[i]);
    }
    for(int i=0;i<j.size();i++)
        qDebug() << jog[i]->getNome();

    atual = 0;
    dados = new Util_b(0,0,140,50);
    dados->setPos(-70,-25);
    dados->setText("Jogar Dados");
    dados->addPixMap(QPixmap(":/images/botao.jfif"));
    dados->set_Window(window);
    dados->setAtual(jog[atual]);
    dados->setScene(this);
    addItem(dados);

    d1 = new CardDisplay(0,0,50,50);
    d1->setPos(-70,50);
    d1->addText("0");
    d1->setCor("blue");
    d2 = new CardDisplay(0,0,50,50);
    d2->setPos(20,50);
    d2->addText("0");
    d2->setCor("blue");
    addItem(d1);
    addItem(d2);
    //QPixmap pixmap2(":/images/saida_livre.jfif");
    /*rect = new CardDisplay(0,0,86,121);
    addItem(rect);
    rect->setPos(100,-100);
    rect->setCursor(cursor);
    rect->set_Window(window,lim);*/

    //rect->addPixMap(pixmap2);


    _timer = new QTimer;
    QObject::connect(_timer, &QTimer::timeout, this, &QGraphicsScene::advance);
    _timer->start(1000 / Config::Viewport::FPS);
    qDebug() << "INIT";



}
void JogoScene::setDados(int d_1, int d_2){
    qDebug()<<"atualiza dados";
    d1->addText(QString::number(d_1));
    d2->addText(QString::number(d_2));
    d1->setVisible(false);
    d2->setVisible(false);
    d1->setVisible(true);
    d2->setVisible(true);
}
bool JogoScene::getEspera(){
    return espera;
}
void JogoScene::setEspera(bool a){
    espera = a;
}

void JogoScene::getTab(QString fi){
    QFile file(fi);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    vector<Casa *> casas;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line = line.split(';').first();
        //qDebug() << line;
        if (line.split(',').first() == "Inicio"){
            casas.push_back(new Casa("Ponto de Partida"));
        }
        else if (line.split(',').first() == "Cadeia"){
            casas.push_back(new Casa("Cadeia"));
        }
        else if (line.split(',').first() == "Parada"){
            casas.push_back(new Casa("Parada Livre"));
        }
        else if (line.split(',').first() == "Policia"){
            casas.push_back(new Prender("Vá para Prisão"));
        }
        else if (line.split(',').first() == "Propriedade"){
            vector<int> numbers;
            numbers.push_back(stoi(line.split(',')[7].toStdString()));
            numbers.push_back(stoi(line.split(',')[8].toStdString()));
            numbers.push_back(stoi(line.split(',')[9].toStdString()));
            numbers.push_back(stoi(line.split(',')[10].toStdString()));
            casas.push_back(new Propriedade(QString(line.split(',')[1]),
                                            QString(line.split(',')[2]),
                                            stoi(line.split(',')[3].toStdString()),
                                            stoi(line.split(',')[4].toStdString()),
                                            stoi(line.split(',')[5].toStdString()),
                                            stoi(line.split(',')[6].toStdString()),
                                            numbers));
        }
        else if (line.split(',').first() == "Usina"){
            vector<int> numbers;
            numbers.push_back(stoi(line.split(',')[7].toStdString()));
            casas.push_back(new Propriedade(QString(line.split(',')[1]),
                                            QString(line.split(',')[2]),
                                            stoi(line.split(',')[3].toStdString()),
                                            stoi(line.split(',')[4].toStdString()),
                                            stoi(line.split(',')[5].toStdString()),
                                            stoi(line.split(',')[6].toStdString()),
                                            numbers));
        }
        else if (line.split(',').first() == "SorteReves"){
            casas.push_back(new Sorte_Reves(baralho));
        }
        qDebug()<< line.split(';').first().split(',');
    }

    tabuleiro = new Tabuleiro(casas,0,0,594,594);
    addItem(tabuleiro);
    tabuleiro->setPos(-295,-295);
    vector<Tabuleiro *> t;
    t.push_back(tabuleiro);
    Config::Game::getInstance()->set_tab(t);
    vector<int> ini(0);
    Config::Game::getInstance()->set_tab_seq(ini);
    qDebug() << "getTabfim";

}

void JogoScene::getBaralho(QString fi){
    QFile file(fi);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
    }
    vector<Carta *> cartas;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        line = line.split(';').first();
        //qDebug() << line;
        if (line.split(',').first() == "padrao"){
            if(line.split(',')[1]== "reves")
                cartas.push_back(new Base(Base::c_type::DINHEIRO,-stoi(line.split(',')[3].toStdString()),QString(line.split(',')[2])));
            else
                cartas.push_back(new Base(Base::c_type::DINHEIRO,stoi(line.split(',')[3].toStdString()),QString(line.split(',')[2])));
        }
        qDebug()<< line.split(';').first().split(',');
    }
    baralho = new Baralho(cartas);
    /*
    tabuleiro = new Tabuleiro(casas,0,0,594,594);
    addItem(tabuleiro);
    tabuleiro->setPos(-295,-295);
    vector<Tabuleiro *> t;
    t.push_back(tabuleiro);
    Config::Game::getInstance()->set_tab(t);
    vector<int> ini(0);
    Config::Game::getInstance()->set_tab_seq(ini);
    qDebug() << "getTabfim";*/

}

void JogoScene::nextJog()
{
    qDebug() << jog[atual]->getDenovo();
    if(!jog[atual]->getDenovo()){
        jog[atual]->itemVisible(false);
        atual = (atual + 1)%jog.size();
        qDebug() << "jog[atual]->getNome()";
        jog[atual]->itemVisible(true);
        dados->setAtual(jog[atual]);
    }
}

void JogoScene::setAxis(bool value)
{
    if(value){
        x_axis->show();
        y_axis->show();
    } else {
        x_axis->hide();
        y_axis->hide();
    }
}

void JogoScene::open()
{
    qDebug() << "Button Press Event in Scene";
    window->changeScene(1);
}

void JogoScene::mousePressEvent(QGraphicsSceneMouseEvent  *event){
    qDebug() << "mouse Press Event in Scene";
    qDebug() << event->pos();
    QGraphicsScene::mousePressEvent(event);
}

void JogoScene::keyPressEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}

void JogoScene::keyReleaseEvent(QKeyEvent *event){
    qDebug() << "mouse Press Event in Scene";
}
