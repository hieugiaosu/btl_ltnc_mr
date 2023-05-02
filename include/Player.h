#ifndef PLAYER_H
#define PLAYER_H
#include<bits/stdc++.h>
#include "Board.h"
#include "GuiSystem.h"
#include "ListOfPair.h"
#define INFINITY_VALUE 64000
    using namespace std;
class Player{
    protected:
        int turn;
        string name;
    public:
        virtual int* make_move(Board* board,void * ptr) = 0;
};
class ComputerLV1 : public Player{
    public:
        ComputerLV1(int turn, string name);
        int* make_move(Board* board,void *ptr);
};
class ComputerLV2 : public Player{
    private:
        int heuristic(int** board, int turn);
        int* bestmove(Board* curr,int** board,int turn,int depth, ListOfPair* validmoves, int min1, int min2);
        int bestmoveRec(Board* curr,int** board, int turn, int depth,int min1, int min2);
    public:
        ComputerLV2(int turn, string name);
        int* make_move(Board* board, void *ptr);
};
class HumanPlayer : public Player{
    public:
        HumanPlayer(int turn, string name);
        int* make_move(Board* board, void* ptr);
};
#endif