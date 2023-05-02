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
    pair<int,int> move;
    this->gui->init();
    while (looping){
        vector<vector<int> > curr = this->board->getCurrBoardState();
        this->gui->drawCurrState(curr);
        if (turn == 1) move = this->player1->make_move(*this->board,this->gui);
        else move = this->player2->make_move(*this->board,this->gui);
        this->board->changeBoardState(move,turn);
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        // sleep_for(nanoseconds(10));
        // sleep_until(system_clock::now() + seconds(1));
        // sleep(1);
        // std::this_thread::sleep_for(std::chrono::seconds(1));
        turn*=-1;
        curr = this->board->getCurrBoardState();
        this->gui->drawCurrState(curr);
        looping = !this->board->terminateBoardStateCheck();
    }
}

Game::~Game(){}