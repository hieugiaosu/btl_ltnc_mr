#include "include/Player.h"

ComputerLV1::ComputerLV1(int turn, string name){
    this->turn = turn;
    this->name = name;
}

pair<int,int> ComputerLV1::make_move(Board board, void *ptr ){
    vector<pair<int,int> > valid_moves = board.getValidMoves(this->turn);
    return valid_moves[(int)rand()%(valid_moves.size())];
}

ComputerLV2::ComputerLV2(int turn,string name){
    this->turn = turn;
    this->name = name;
}

pair<int,int> ComputerLV2::make_move(Board board, void *ptr ){
    vector<pair<int,int> > valid_moves = board.getValidMoves(this->turn);
    Board* curr = new Board();
    pair<int,int> best_move = this->bestmove(*curr,board.getCurrBoardState(),this->turn,5,valid_moves,-64000,-64000);
    delete curr;
    return best_move;
}

int ComputerLV2::heuristic(vector<vector<int> > board, int turn){
    static int heuristicTable[8][8] = {
        {100, -50, 10, 5, 5, 10, -50, 100},
        {-50, -100, -1, -1, -1, -1, -100, -50},
        {10, -1, 3, 2, 2, 3, -1, 10},
        {5, -1, 2, 1, 1, 2, -1, 5},
        {5, -1, 2, 1, 1, 2, -1, 5},
        {10, -1, 3, 2, 2, 3, -1, 10},
        {-50, -100, -1, -1, -1, -1, -100, -50},
        {100, -50, 10, 5, 5, 10, -50, 100}
    };
    int score = 0;
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++){
            if (board[i][j]==turn) score+=heuristicTable[i][j];
            if (board[i][j]==-1*turn) score -=heuristicTable[i][j];
        }
    } 
}

pair<int,int> ComputerLV2::bestmove(Board& curr,vector<vector<int> > board, int turn, int depth, vector<pair<int,int> > valid_moves,int min1, int min2){
    if (valid_moves[0].first == BOARD_SIZE && valid_moves[0].second == BOARD_SIZE) return valid_moves[0];
    int best_move_idx = 0;
    int score = 0;
    int maxScore = -64000;
    curr.setBoardState(board);
    for (int i = 0;i<valid_moves.size();i++) {
        if (min1>-1*min2) break;
        curr.setBoardState(board);
        curr.changeBoardState(valid_moves[i],turn);
        score = -1*bestmoveRec(curr,curr.getCurrBoardState(),-1*turn,depth-1,min1,min2);
        if (score > maxScore) {
            maxScore = score;
            best_move_idx = i;
        }
        if (turn == 1 ) min1 = (score>min1)?score:min1;
        else min1 = (score>min2)?score:min2;
    }
    return valid_moves[best_move_idx];
} 

int ComputerLV2::bestmoveRec(Board& curr,vector<vector<int> > board, int turn, int depth,int min1, int min2){
    if (depth == 0) return this->heuristic(board,turn);
    curr.setBoardState(board);
    if (curr.terminateBoardStateCheck()){
        return curr.getWinner()*turn*1e6;
    }
    vector<pair<int,int> > valid_moves = curr.getValidMoves(turn);
    if (valid_moves[0].first == BOARD_SIZE && valid_moves[0].second == BOARD_SIZE)
        return -1*this->bestmoveRec(curr,board,turn*(-1),depth-1,min1,min2);
    int score =0;
    int maxScore = -64000;
    for (int i = 0;i<valid_moves.size();i++) {
        if (min1>-1*min2) break;
        curr.setBoardState(board);
        curr.changeBoardState(valid_moves[i],turn);
        score = -1*bestmoveRec(curr,curr.getCurrBoardState(),-1*turn,depth-1,min1,min2);
        if (score > maxScore) {
            maxScore = score;
        }
        if (turn == 1 ) min1 = (score>min1)?score:min1;
        else min1 = (score>min2)?score:min2;
    }
    return maxScore;
}

HumanPlayer::HumanPlayer(int turn, string name){
    this->turn = turn;
    this->name = name;
}

pair<int,int> HumanPlayer::make_move(Board board, void* ptr){
    GuiSystem * agent = (GuiSystem *)ptr;
    vector<pair<int,int> > valid_moves = board.getValidMoves(this->turn);
    int idx = agent->waitForChoosingMove(valid_moves);
    return valid_moves[idx]; 
}