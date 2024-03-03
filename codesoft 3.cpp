#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void switchPlayer(char& currentPlayer);
bool playAgain();

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;

    do {
        initializeBoard(board);

        while (true) {
            displayBoard(board);

            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                    break;
                }
                if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    break;
                }
                switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
    } while (playAgain());

    cout << "Thanks for playing Tic-Tac-Toe! Goodbye!" << endl;

    return 0;
}
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(char board[3][3], char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
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

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
