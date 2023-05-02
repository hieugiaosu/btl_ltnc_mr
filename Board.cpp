#include "include/Board.h"

Board::Board(){
    this->board = vector<vector<int> >(8,vector<int>(8,0));
    this->board[3][3] = this->board[4][4] = 1;
    this->board[3][4] = this->board[4][3] = -1; 
}

Board::Board(vector<vector<int> > board){
    this->board = board;
}

void Board::setBoardState(vector<vector<int> > board){
    this->board = board;
}

vector<vector<int> > Board::getCurrBoardState(){
    return this->board;
}

void Board::changeBoardState(pair<int,int> move, int turn){
    int row = move.first;
    int col = move.second;
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


bool Board::validMoveCheck(pair<int,int> move,int turn){
    int row = move.first;
    int col = move.second;
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

vector<pair<int,int> > Board::getValidMoves(int turn){
    vector<pair<int,int> > moves;
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++) {
            pair<int,int> move = pair<int,int>(i,j);
            if (this->validMoveCheck(move,turn)){
                moves.push_back(move);
            }
        }
    }
    if (moves.size()==0) moves.push_back(pair<int,int>(BOARD_SIZE,BOARD_SIZE));
    return moves;
}

bool Board::terminateBoardStateCheck(){
    vector<pair<int,int> > valid1 = this->getValidMoves(1);
    vector<pair<int,int> > valid2 = this->getValidMoves(-1);
    return (valid1[0].first==BOARD_SIZE && valid1[0].second==BOARD_SIZE && valid2[0].first==BOARD_SIZE && valid2[0].second==BOARD_SIZE);
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
    this->board = vector<vector<int> >(8,vector<int>(8,0));
    this->board[3][3] = this->board[4][4] = 1;
    this->board[3][4] = this->board[4][3] = -1; 
}

Board::~Board(){}

// void printBoard(vector<vector<int> > board){
//     for (int i=0;i<8;i++){
//         for (int j=0;j<8;j++) cout<<board[i][j]<<"  ";
//         cout<<endl;
//     }
// }

// int main(){
//     Board board;
//     printBoard(board.getCurrBoardState());
//     board.changeBoardState(pair<int,int>(3,5),1);
//     cout<<"------------------\n";
//     printBoard(board.getCurrBoardState());
//     return 0;
// }