#include "Game.cpp"

int main(){
    cout<<"1\n";
    HumanPlayer *player1 = new HumanPlayer(1,"YOU");
    cout<<"2\n";
    ComputerLV1 *player2 = new ComputerLV1(-1,"Com");
    cout<<"3\n";
    Board* board = new Board;
    cout<<"4\n";
    GuiSystem * gui = new GuiSystem;
    cout<<"5\n";
    Game * game = new Game(player1,player2,board,gui);
    cout<<"6\n";
    bool flag = false;
    try
    {
        game->gameLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout<<"error";
        delete game;
        delete gui;
        delete board;
        delete player2;
        delete player1;
        flag = true;

    }
    
    // game->gameLoop();
    if (!flag){
    delete game;
    delete gui;
    delete board;
    delete player2;
    delete player1;
    }
    return 0;

}