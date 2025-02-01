#include<stdio.h>
#include<conio.h>

// Function to print the positions of the grids
void positionBoard(int box[3][3]) {
    printf("\n");
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %d ", box[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to display the game board
void displayBoard(char box[3][3]) {
    printf("\n");
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", box[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to validate the player's move
int isValidMove(int move, char box[3][3]) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return (move >= 1 && move <= 9 && box[row][col] == ' ');
}

// Function to update the board with the player's move
void updateBoard(int move, char player, char box[3][3]) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    box[row][col] = player;
}

// Function to check if there is a winner
int checkWinner(char box[3][3]) {
    // Check rows and columns
    int i;
    for (i = 0; i < 3; i++) {
        if (box[i][0] == box[i][1] && box[i][1] == box[i][2] && box[i][0] != ' ') return 1;
        if (box[0][i] == box[1][i] && box[1][i] == box[2][i] && box[0][i] != ' ') return 1;
    }
    // Check diagonals
    if (box[0][0] == box[1][1] && box[1][1] == box[2][2] && box[0][0] != ' ') return 1;
    if (box[0][2] == box[1][1] && box[1][1] == box[2][0] && box[0][2] != ' ') return 1;
    return 0;
}

// Main game function
void playGame() {
    char box[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int move, turns = 0;
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
    printf("TIC - TAC - TOE\n");
    printf("Rules: Enter your move (1-9) based on the grid positions.\n");
	positionBoard(arr);
	
    while (turns < 9) {
        displayBoard(box);
        printf("Player %c, Enter your move (1 - 9): ", player);
        scanf("%d", &move);

        if (isValidMove(move, box)) {
            updateBoard(move, player, box);
            if (checkWinner(box)) {
                displayBoard(box);
                printf("Player %c wins!\n", player);
                return;
            }
            player = (player == 'X') ? 'O' : 'X';
            turns++;
        } 
		else {
            printf("Invalid move. Try again.\n");
        }
    }
    displayBoard(box);
    printf("It's a draw!\n");
}

int main() {
    playGame();
    getch();
    return 0;
}