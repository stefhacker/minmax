#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include <vector>

class tic_tac_toe {
    private:
        std::vector<std::vector<char>> board;
        char current_player;
        void initialize(){
            board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        }
        
       
       
    public:
        tic_tac_toe();
        void make_move(int row, int col);
        void display_board_state();
        char check_winner();
        bool draw();
        int evaluate();
        int maxi();
        int mini();
        std::pair<int, int> minimax();

};




#endif