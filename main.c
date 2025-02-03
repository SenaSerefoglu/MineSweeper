#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16
#define MINES 40

int board[SIZE][SIZE] = {0};
char display[SIZE][SIZE];
int revealed[SIZE][SIZE] = {0};
int selectedRow, selectedCol;

void initializeBoard();
void placeMines();
void calculateNumbers();
void resetGame();
void displayBoard();
void revealCell(int, int);
void getUserInput();
void playGame();
void gameOver();

void initializeBoard() {
    resetGame();
    placeMines();
    calculateNumbers();
}

void resetGame() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
            revealed[i][j] = 0;
            display[i][j] = '-';
        }
    }
}

void placeMines() {
    srand(time(NULL));
    int placedMines = 0;
    
    while (placedMines < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        
        if (board[x][y] == 9) continue;
        board[x][y] = 9;
        placedMines++;
    }
}

void calculateNumbers() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y] == 9) continue;
            
            int mineCount = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + i, ny = y + j;
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == 9) {
                        mineCount++;
                    }
                }
            }
            board[x][y] = mineCount;
        }
    }
}

void displayBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", display[i][j]);
        }
        printf("\n");
    }
}

void revealCell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y]) return;
    
    revealed[x][y] = 1;
    display[x][y] = board[x][y] + '0';
    
    if (board[x][y] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i != 0 || j != 0) revealCell(x + i, y + j);
            }
        }
    }
}

void getUserInput() {
    printf("Enter row and column (0-15): ");
    scanf("%d %d", &selectedRow, &selectedCol);
}

void playGame() {
    while (1) {
        displayBoard();
        getUserInput();
        
        if (board[selectedRow][selectedCol] == 9) {
            gameOver();
            return;
        }
        
        revealCell(selectedRow, selectedCol);
    }
}

void gameOver() {
    printf("Game Over! You hit a mine.\n");
    initializeBoard();
    playGame();
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}