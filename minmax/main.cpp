#include <iostream>
#include "tictactoe.h"



int main() {
    
    std::cout << "do you want to start a game ?[Y/n]\n";
    char yes_no;
    std::cin >> yes_no;
    if (yes_no != 'Y') {
        return 0;
    }
    tic_tac_toe game;
    while(!game.draw() && game.check_winner() == ' ') {
        
        std::pair ai_move = game.minimax();
        game.make_move(ai_move.first, ai_move.second);
        if (game.check_winner() != ' ' || game.draw()) {
            game.display_board_state();
            break;  
        }
        game.display_board_state();
        std::cout << "in which row u want to place? (int between 0 and 2)\n";
        int row;
        std::cin >> row;
        std::cout << "in which col u want to place? (int between 0 and 2)\n";
        int col;
        std::cin >> col;
        game.make_move(row, col);
        if(game.check_winner() != ' ' || game.draw()) {
                game.display_board_state();
            	break;  
        }
        
        
    
    }

    if (game.check_winner() == 'X'){
        std::cout << "you lost";
        return 0;
    }

    if (game.check_winner() == 'O'){
        std::cout << "you won";
        return 0;
    }
    if(game.draw()){
        std::cout << "draw";
        return 0;
    }

    
    

    
    
}

