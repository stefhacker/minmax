#include <vector>
#include <iostream>
#include "tictactoe.h"

tic_tac_toe::tic_tac_toe(){
    current_player = 'X';
    initialize();
}

void tic_tac_toe::make_move(int row, int col){
      if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' '){
            board[row][col] = current_player;
            current_player = 'O';
      }
    
}

void tic_tac_toe::display_board_state(){
     for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << ' ' << '|'  << ' ';
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------" << std::endl;
        }
    }


 bool tic_tac_toe::check_winner() {
        for (int i = 0; i < 3; ++i){
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                
                return true;
            } 
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                
                return true;
            } 
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
             
            return true;
        } 
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){

            return true;
        } 
        return false;
    }

    // Function to check if the board is full (i.e., game is a draw)
    bool tic_tac_toe::draw(){
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') 
                return false;
            }
        }
        return true;
    }


