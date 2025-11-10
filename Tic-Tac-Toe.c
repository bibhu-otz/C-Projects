#include <stdio.h>

#define SIZE 3

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int player);
void togglePlayer(int *player);
void newGame(char board[SIZE][SIZE], int *player);

int main() {
    char board[SIZE][SIZE];
    int currentPlayer = 1;
    int winner = 0;
    char playAgain;

    do {
        newGame(board, &currentPlayer);

        while(1) {
            displayBoard(board);
            makeMove(board, currentPlayer);
            
            // Check if the current player wins
            winner = checkWin(board);
            if (winner) {
                displayBoard(board);
                printf("Player %d wins!\n", currentPlayer);
                break;
            }
            
            // Check if the board is full (draw)
            if (isBoardFull(board)) {
                displayBoard(board);
                printf("It's a draw!\n");
                break;
            }
            
            // Toggle player
            togglePlayer(&currentPlayer);
        }

        // Ask if the players want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}

// Function to initialize the game board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE]) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to make a move for the current player
void makeMove(char board[SIZE][SIZE], int player) {
    int row, col;
    char mark = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Player %d, enter row (1-3) and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        row--; col--;  // Convert to 0-based index

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = mark;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

// Function to toggle between players
void togglePlayer(int *player) {
    *player = (*player == 1) ? 2 : 1;
}

// Function to start a new game
void newGame(char board[SIZE][SIZE], int *player) {
    initializeBoard(board);
    *player = 1;
}
