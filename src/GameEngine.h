//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
#define CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H

#include "Windows.h"
#include <iostream>
using std::ostream;

class Board;
class Controller;

class GameEngine {
private:
    Board* board;
    Controller* controller;

public:
    GameEngine();
    GameEngine(const GameEngine& ge);
    ~GameEngine();

    GameEngine& operator=(const GameEngine& ge);
    friend ostream& operator<<(ostream& output, const GameEngine& ge);

    void clearScreen() {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
    };

    void play();
};


#endif //CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
