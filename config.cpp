#include "config.h"

Config::Game * Config::Game::instance = nullptr;

Config::Game::Game()
{

}

Config::Game *Config::Game::getInstance()
{
    if (instance == nullptr )
        instance = new Game();
    return instance;
}
