//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "GameEngine.h"


int main() {
    
    GameEngine* ge = new GameEngine();

    ge->play();

    delete ge;
    ge = nullptr;

    return 0;
}
