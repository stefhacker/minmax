#include <iostream>
#include "tictactoe.h"



int main() {
    tic_tac_toe game;
    // Find the best move for 'X'
    std::pair<int, int> bestMove1 = game.minimax();

    // does not work properly
    game.make_move(0, 0); // X
    game.make_move(0, 1); // O
    game.make_move(0, 2); // X
    game.make_move(1, 1); // O
    game.make_move(2, 0); // X
    game.make_move(2, 2);
    std::cout << "Board before AI's move:\n";
    game.display_board_state();

    // AI's move - expected to make a winning move
    std::pair<int, int> ai_move = game.minimax();
    game.make_move(ai_move.first, ai_move.second);

    std::cout << "\nAI selects move: (" << ai_move.first << ", " << ai_move.second << ")\n";
    std::cout << "Board after AI's move:\n";
    game.display_board_state();
    

    return 0;
    
}

