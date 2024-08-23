#include <iostream>
#include "tictactoe.h"

void minmax(){
    

}

int main(){

    tic_tac_toe game;  // Create an instance of the TicTacToe class
    auto best_move = game.get_best_move();
    std::cout << "Best move: (" << best_move.first << ", " << best_move.second << ")" << std::endl;
    game.make_move(best_move.first, best_move.second);
    game.display_board_state();
    
    return 0;

}


