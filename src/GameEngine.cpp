//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "GameEngine.h"
#include "Board.h"
#include "Controller.h"
#include "Snake.h"
#include "Apple.h"

#include "Windows.h"
#include "iostream"
using std::cout;
using std::endl;

GameEngine::GameEngine(): score(0), refreshRate(100) {
    this->board = new Board();
    this->controller = new Controller();
}

GameEngine::GameEngine(const GameEngine& ge): score(ge.score), refreshRate(ge.refreshRate) {
    this->board = new Board(*ge.board);
    this->controller = new Controller(*ge.controller);
}

GameEngine::~GameEngine() {

    delete this->board;
    delete this->controller;

    this->board = nullptr;
    this->controller = nullptr;
}

GameEngine& GameEngine::operator=(const GameEngine &ge) {

    if (this == &ge) {
        return *this;
    }

    this->board = new Board(*ge.board);
    this->controller = new Controller(*ge.controller);
    this->score = ge.score;
    this->refreshRate = ge.refreshRate;

    return *this;
}

ostream& operator<<(ostream& output, const GameEngine& ge) {
    return output;
}

void GameEngine::refresh() {
    cout << endl << "\t\t\tSCORE: " << this->score << endl << endl;
    cout << *this->board;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

void GameEngine::play() {

    bool gameOver = false;

    while (!gameOver) {
        GameEngine::refresh();
        this->controller->readInput(this->board);
        this->board->getSnake()->move();

        if (this->board->getSnake()->hasCollided()) {
            gameOver = true;
        }

        if (this->board->getSnake()->isEating(*this->board->getApple()->getCoordinate())) {
            this->board->getApple()->generateNewFood();
            this->board->getSnake()->grow();
            this->incrementScore();
        }

        Sleep(this->refreshRate);
    }

    this->partingScreen();

}

void GameEngine::incrementScore() {
    this->score += 10;
    
    if (this->score % 100 == 0) increaseRefreshRate();
};

void GameEngine::increaseRefreshRate() { this->refreshRate /= 1.5; };

void GameEngine::partingScreen() {
    system("CLS");
    cout << endl << "\t\t\tGAME OVER" << endl;
    cout << endl << "\t\t\tFINAL SCORE: " << this->score << endl << endl;
    cout << *this->board;
    cout << endl << endl <<"Thank you for playing :)" << endl << endl;
}
