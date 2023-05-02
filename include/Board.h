#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
    using namespace std;
#define BOARD_SIZE 8
class Board{
    private:
        vector<vector<int> > board;
    public:
        Board();
        Board(vector<vector<int> > board);
        void setBoardState(vector<vector<int> > board);
        bool validMoveCheck(pair<int,int> move, int turn);
        vector<pair<int,int> > getValidMoves(int turn);
        void changeBoardState(pair<int,int> move,int turn);
        vector<vector<int> > getCurrBoardState();
        bool terminateBoardStateCheck();
        int getWinner();
        void reset();
        ~Board();
};
#endif