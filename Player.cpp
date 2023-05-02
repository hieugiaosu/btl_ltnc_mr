#include "include/Player.h"

ComputerLV1::ComputerLV1(int turn, string name){
    this->turn = turn;
    this->name = name;
}

int* ComputerLV1::make_move(Board* board, void *ptr ){
    ListOfPair* valid_moves = board->getValidMoves(this->turn);
    if (valid_moves == NULL) return NULL;
    int idx = (int)rand()%(valid_moves->getSize());
    int* ans = new int[2];
    ans[0] = *valid_moves[idx][0];
    ans[1] = *valid_moves[idx][1];
    delete valid_moves;
    return ans;
}

ComputerLV2::ComputerLV2(int turn,string name){
    this->turn = turn;
    this->name = name;
}

int* ComputerLV2::make_move(Board* board, void *ptr ){
    ListOfPair* valid_moves = board->getValidMoves(this->turn);
    Board* curr = new Board();
    int* best_move = this->bestmove(curr,board->getCurrBoardState(),this->turn,5,valid_moves,-1*INFINITY_VALUE,-1*INFINITY_VALUE);
    delete curr;
    delete valid_moves;
    return best_move;
}

int ComputerLV2::heuristic(int** board, int turn){
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

int* ComputerLV2::bestmove(Board* curr,int** board, int turn, int depth, ListOfPair* valid_moves,int min1, int min2){
    if (valid_moves == NULL) return NULL;
    int best_move_idx = 0;
    int score = 0;
    int maxScore = -1*INFINITY_VALUE;
    int** curr_board = new int*[BOARD_SIZE];
    for (int i=0;i<BOARD_SIZE;i++){
        curr_board[i] = new int[BOARD_SIZE];
        for (int j=0;j<BOARD_SIZE;j++) curr_board[i][j] = board[i][j];
    }
    curr->setBoardState(curr_board);
    for (int i = 0;i<valid_moves->getSize();i++) {
        if (min1>-1*min2) break;
        curr->setBoardState(curr_board);
        curr->changeBoardState(*valid_moves[i][0],*valid_moves[i][1],turn);
        score = -1*bestmoveRec(curr,curr->getCurrBoardState(),-1*turn,depth-1,min1,min2);
        if (score > maxScore) {
            maxScore = score;
            best_move_idx = i;
        }
        if (turn == 1 ) min1 = (score>min1)?score:min1;
        else min1 = (score>min2)?score:min2;
    }
    for (int i=0;i<BOARD_SIZE;i++) delete[] curr_board[i];
    delete[] curr_board;
    return (valid_moves[0][best_move_idx]);
} 

int ComputerLV2::bestmoveRec(Board* curr,int** board, int turn, int depth,int min1, int min2){
    if (depth == 0) return this->heuristic(board,turn);
    if (curr->terminateBoardStateCheck()){
        return curr->getWinner()*turn*INFINITY_VALUE;
    }
    int** curr_board = new int*[BOARD_SIZE];
    for (int i=0;i<BOARD_SIZE;i++){
        curr_board[i] = new int[BOARD_SIZE];
        for (int j=0;j<BOARD_SIZE;j++) curr_board[i][j] = board[i][j];
    }
    curr->setBoardState(curr_board);
    ListOfPair* valid_moves = curr->getValidMoves(turn);
    if (valid_moves == NULL){
        delete valid_moves;
        for (int i=0;i<BOARD_SIZE;i++) delete[] curr_board[i];
        delete[] curr_board;
        return -1*this->bestmoveRec(curr,board,turn*(-1),depth-1,min1,min2);
    }
    int score = 0;
    int maxScore = -1*INFINITY_VALUE;
    for (int i = 0;i<valid_moves->getSize();i++) {
        if (min1>-1*min2) break;
        curr->setBoardState(curr_board);
        curr->changeBoardState(*valid_moves[i][0],*valid_moves[i][1],turn);
        score = -1*bestmoveRec(curr,curr->getCurrBoardState(),-1*turn,depth-1,min1,min2);
        if (score > maxScore) {
            maxScore = score;
        }
        if (turn == 1 ) min1 = (score>min1)?score:min1;
        else min1 = (score>min2)?score:min2;
    }
    delete valid_moves;
    for (int i=0;i<BOARD_SIZE;i++) delete[] curr_board[i];
    delete[] curr_board;
    return maxScore;
}

HumanPlayer::HumanPlayer(int turn, string name){
    this->turn = turn;
    this->name = name;
}

int* HumanPlayer::make_move(Board* board, void* ptr){
    GuiSystem * agent = (GuiSystem *)ptr;
    cout<<"9.1\n";
    ListOfPair* valid_moves = board->getValidMoves(this->turn);
    cout<<"9.2\n";
    int idx = agent->waitForChoosingMove(valid_moves);
    cout<<"9.3\n";
    if (idx == -1) return NULL;
    cout<<"9.4\n";
    int* move = new int[2];
    move[0] = *valid_moves[idx][0];
    move[1] = *valid_moves[idx][1];
    cout<<"9.5\n";
    delete valid_moves;
    cout<<"9.6\n";
    return move; 
}