#include "Game.cpp"

int main(){
    HumanPlayer *player2 = new HumanPlayer(-1,"YOU");
    ComputerLV2 *player1 = new ComputerLV2(1,"Com");
    Board* board = new Board;
    GuiSystem * gui = new GuiSystem;
    Game * game = new Game(player1,player2,board,gui);
    bool flag = false;
    try
    {
        game->gameLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout<<"error \n";
        delete game;
        delete gui;
        delete board;
        delete player2;
        delete player1;
        flag = true;
        cout<<"delete all \n";
    }
    if (!flag){
    delete game;
    delete gui;
    delete board;
    delete player2;
    delete player1;
    }
    return 0;

}