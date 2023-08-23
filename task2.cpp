#include <iostream>
using namespace std;

// Define the board dimensions
const int ROWS = 6;
const int COLS = 7;

// Function to display the current board
void displayBoard(char board[ROWS][COLS]) {
    // Display the headline with column numbers
    for (int i = 0; i < COLS; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout <<endl;
    }
    cout << "______________________" <<endl;
}

// Function to check if a player has won the game
bool checkWin(char board[ROWS][COLS], char player) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Check vertical
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check diagonals (left to right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check diagonals (right to left)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLS; j++) {
            if (board[i][j] == player && board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }

    return false;
}

// Function to check if the board is full (a draw)
bool checkDraw(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[ROWS][COLS];
    char currentPlayer = 'X';
    bool gameOver = false;

    // Initialize the board with empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    while (!gameOver) {
        // Display the current board
        displayBoard(board);

        // Ask the current player to make a move
        int col;
        cout << "Player " << currentPlayer << ", enter your column (0-" << COLS - 1 << "): ";
        cin >> col;

        // Check if the column is valid and has empty cells
        if (col >= 0 && col < COLS && board[0][col] == ' ') {
            // Place the player's piece in the selected column
            for (int i = ROWS - 1; i >= 0; i--) {
                if (board[i][col] == ' ') {
                    board[i][col] = currentPlayer;
                    break;
                }
            }

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) { // Check if the game is a draw
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                // Switch to the other player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

