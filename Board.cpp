#include "include/Board.h"

Board::Board(){
    this->board = new int*[BOARD_SIZE];
    for(int i=0;i<BOARD_SIZE;i++){
        this->board[i] = new int[BOARD_SIZE];
        for (int j=0;j<BOARD_SIZE;j++) this->board[i][j] = 0;
    }
    this->board[3][3] = this->board[4][4] = 1;
    this->board[3][4] = this->board[4][3] = -1; 

}

Board::Board(int** board){
    this->board = new int*[BOARD_SIZE];
    for(int i=0;i<BOARD_SIZE;i++){
        this->board[i] = new int[BOARD_SIZE];
        for (int j=0;j<BOARD_SIZE;j++) this->board[i][j] = board[i][j];
    }
}

void Board::setBoardState(int** board){
    for(int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++) this->board[i][j] = board[i][j];
    }
}

int** Board::getCurrBoardState(){
    return this->board;
}

void Board::changeBoardState(int row, int col, int turn){
    if (row==BOARD_SIZE && col==BOARD_SIZE) return;
    int r,c;
    bool flipped;
    for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
            if (i==0 && j==0) continue;
            r = row + i;
            c = col + j;
            flipped = false;
            vector<pair<int,int> > flip_list;
            while (r>=0 && r<BOARD_SIZE && c>=0 && c<BOARD_SIZE){
                if (this->board[r][c]==0) break;
                if (this->board[r][c]==turn){ 
                    flipped = true;
                    break;
                }
                flip_list.push_back(pair<int,int>(r,c));
                r+=i;
                c+=j;
            }
            if (flipped){
                // for (auto flip = flip_list.begin(); flip != flip_list.end();flip++){
                //     this->board[flip->first][flip->second] = turn;
                // }
                for (int i=0; i<flip_list.size();i++){
                    this->board[flip_list[i].first][flip_list[i].second]=turn;
                }
            }
        }
    }
    this->board[row][col]=turn;
}


bool Board::validMoveCheck(int row, int col ,int turn){
    if (this->board[row][col]!=0) return 0;
    int r,c;
    bool found_oponent;
    for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
            if (i==0 && j==0) continue;
            r = row + i;
            c = col + j;
            found_oponent = false;
            while (r>=0 && r<BOARD_SIZE && c>=0 && c<BOARD_SIZE){
                if (this->board[r][c]==0) break;
                if (this->board[r][c]==turn){ 
                    if (found_oponent) return 1;
                    break;
                }
                found_oponent = true;
                r+=i;
                c+=j;
            }
        }   
    }
    return 0;
}

ListOfPair* Board::getValidMoves(int turn){
    vector<vector<int> > moves;
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++) {
            if (this->validMoveCheck(i,j,turn)){
                moves.push_back({i,j});
            }
        }
    }
    if (moves.size()==0) return NULL;
    ListOfPair* ans = new ListOfPair(moves.size());
    for (int i=0;i<moves.size();i++) {
        ans->add(moves[i][0],moves[i][1]);
    }
    return ans;
}

bool Board::terminateBoardStateCheck(){
    ListOfPair* valid1 = this->getValidMoves(1);
    if (valid1 != NULL) {
        delete valid1;
        return false;
    }
    ListOfPair* valid2 = this->getValidMoves(-1);
    if (valid2 != NULL) {
        delete valid2;
        return false;
    }
    return true;
}

int Board::getWinner(){
    int sum=0;
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            sum+=this->board[i][j];
        }    
    }
    if (sum<0) return -1;
    if (sum>0) return 1;
    return 0;
}

void Board::reset(){
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++){
            this->board[i][j] = 0;
        }
    }
    this->board[3][3] = this->board[4][4] = 1;
    this->board[3][4] = this->board[4][3] = -1; 
}

// void Board::freeList(int** list, int n){
//     for (int i = 0;i<n;i++) {
//         delete list[i];
//     }
//     delete list;
// }

Board::~Board(){
    for (int i=0;i<BOARD_SIZE;i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

