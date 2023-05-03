#include "include/Game.h"
#include "Board.cpp"
#include "GuiSystem.cpp"
#include "Player.cpp"
#include <chrono>
#include <thread>
Game::Game(Player* player1, Player* player2, Board* board, GuiSystem *gui){
    this->player1 = player1;
    this->player2 = player2;
    this->board = board;
    this->gui = gui;
}

void Game::gameLoop(){
    int turn = 1;
    bool looping = true;
    int* move;
    this->gui->init();
    while (looping){
        int** curr = this->board->getCurrBoardState();
        this->gui->drawCurrState(curr);
        if (turn == 1) move = this->player1->make_move(this->board,this->gui);
        else move = this->player2->make_move(this->board,this->gui);
        if (move == NULL) {
            turn*=-1;
            continue;
        }
        this->board->changeBoardState(move[0],move[1],turn);
        turn*=-1;
        delete[] move;
        curr = this->board->getCurrBoardState();
        this->gui->drawCurrState(curr);
        this->gui->delayMiliSeconds(100);
        looping = !this->board->terminateBoardStateCheck();
    }
}

Game::~Game(){}