//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "GameEngine.h"
#include <windows.h>

using namespace std;

GameEngine::GameEngine() {
}

GameEngine::GameEngine(const GameEngine& ge) {
}

GameEngine::~GameEngine() {
}

GameEngine& GameEngine::operator=(const GameEngine &ge) {

    if (this == &ge) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const GameEngine& ge) {
    return output;
}

/*
void GameEngine::update() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0})
}*/
