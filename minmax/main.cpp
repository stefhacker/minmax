#include <iostream>
#include "tictactoe.h"



int main() {
    tic_tac_toe game;
    // Find the best move for 'X'
    std::pair<int, int> bestMove1 = game.minimax();

    // does not work properly
    game.make_move(bestMove1.first, bestMove1.second);
    std::cout << "After AI's move:\n";
    game.display_board_state();
    

    return 0;
    
}

