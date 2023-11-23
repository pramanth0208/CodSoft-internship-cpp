//Task 3 C++ internship TIC-TAC-TOE GAME
#include <iostream>
using namespace std;
void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
             cout << board[i][j] << " | ";
        }
         cout <<  endl << "---------" <<  endl;
    }
}
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }
    return false;
}
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

    char currentPlayer = 'X';

    while (true) {
        printBoard(board);
        int row, col;
         cout << "Player " << currentPlayer << ", enter your move (row and column): ";
         cin >> row >> col;
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                 cout << "Player " << currentPlayer << " wins!" <<  endl;
                break;
            }

            if (checkDraw(board)) {
                printBoard(board);
                 cout << "The game is a draw!" <<  endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
        	if(row<=2 && row>=0 && col<=2 && col>=0)
            	cout << "Cell already taken. Try again." <<  endl;
            else
            	cout << "Cell doesn't exit, Try again."<<  endl;
        }
    }

    return 0;
}
