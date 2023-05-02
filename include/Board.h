#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
#include "ListOfPair.h"
    using namespace std;
#define BOARD_SIZE 8
class Board{
    private:
        int** board;
    public:
        Board();
        Board(int** board);
        void setBoardState(int** board);
        bool validMoveCheck(int row, int col, int turn);
        ListOfPair* getValidMoves(int turn);
        void changeBoardState(int row, int col,int turn);
        int**getCurrBoardState();
        bool terminateBoardStateCheck();
        int getWinner();
        void reset();
        // void freeList(int** list, int n);
        ~Board();
};
#endif