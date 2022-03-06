//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#ifndef CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
#define CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H

#include <iostream>
using std::ostream;

class Board;
class Controller;

class GameEngine {
private:
    Board* board;
    Controller* controller;
    int score;
    int refreshRate;

public:
    GameEngine();
    GameEngine(const GameEngine& ge);
    ~GameEngine();

    GameEngine& operator=(const GameEngine& ge);
    friend ostream& operator<<(ostream& output, const GameEngine& ge);

    void refresh();
    void play();

    int getScore() { return this->score; };
    int getRefreshRate() { return this->refreshRate; };

    void incrementScore();
    void increaseRefreshRate();
    void partingScreen();
};


#endif //CONSOLE_APP_SNAKE_GAME_GAMEENGINE_H
