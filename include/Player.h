#ifndef PLAYER_H
#define PLAYER_H
#include<bits/stdc++.h>
#include "Board.h"
#include "GuiSystem.h"
    using namespace std;
class Player{
    protected:
        int turn;
        string name;
    public:
        virtual pair<int,int> make_move(Board board,void * ptr) = 0;
};
class ComputerLV1 : public Player{
    public:
        ComputerLV1(int turn, string name);
        pair<int,int> make_move(Board board,void *ptr);
};
class ComputerLV2 : public Player{
    private:
        int heuristic(vector<vector<int> > board, int turn);
        pair<int,int> bestmove(Board& curr,vector<vector<int> > board,int turn,int depth, vector<pair<int,int> > validmoves, int min1, int min2);
        int bestmoveRec(Board& curr,vector<vector<int> > board, int turn, int depth,int min1, int min2);
    public:
        ComputerLV2(int turn, string name);
        pair<int,int> make_move(Board board, void *ptr);
};
class HumanPlayer : public Player{
    public:
        HumanPlayer(int turn, string name);
        pair<int,int> make_move(Board board, void* ptr);
};
#endif