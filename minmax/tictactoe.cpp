#include <vector>
#include <iostream>
#include <algorithm>
#include "tictactoe.h"

tic_tac_toe::tic_tac_toe() {
    current_player = 'X';
    initialize();
}

void tic_tac_toe::make_move(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = current_player;
        current_player = (current_player == 'O') ? 'X' : 'O';
    } else {
        std::cout << "Invalid move. Please choose an empty cell within the board.\n";
    }
}

void tic_tac_toe::display_board_state() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------\n";
    }
}

char tic_tac_toe::check_winner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

int tic_tac_toe::evaluate() {
    char winner = check_winner();
    if (winner == 'X') return 1;
    if (winner == 'O') return -1;
    return 0;
}

bool tic_tac_toe::draw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return check_winner() == ' ';
}

int tic_tac_toe::maxi() {
    if (draw() || check_winner() != ' ') {
        return evaluate();
    }
    
    int v = -5000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';  // Simulate move for 'X'
                int moveVal = mini();  // Get the minimizer's response
                v = std::max(v, moveVal);
                board[i][j] = ' ';  // Undo the move
            }
        }
    }
    return v;
}

int tic_tac_toe::mini() {
    if (draw() || check_winner() != ' ') {
        return evaluate();
    }

    int v = 5000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';  // Simulate move for 'O'
                int moveVal = maxi();  // Get the maximizer's response
                v = std::min(v, moveVal);
                board[i][j] = ' ';  // Undo the move
            }
        }
    }
    return v;
}

std::pair<int, int> tic_tac_toe::minimax() {
    int bestVal = -5000;
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';  // Assume 'X' is the maximizing player
                int moveVal = mini();  // Evaluate this move
                board[i][j] = ' ';  // Undo the move

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }

    
    return bestMove;
}


  


