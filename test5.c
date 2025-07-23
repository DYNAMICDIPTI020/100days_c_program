#include <stdio.h>

char board[3][3];

void initBoard() {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin() {
    for (int i=0; i<3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;
    return 0;
}

int checkDraw() {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int row, col, player = 0;
    char mark;
    initBoard();

    printf("Tic-Tac-Toe (Cross and Zero)\n");
    printf("Player 1: X   Player 2: O\n");

    while (1) {
        printBoard();
        mark = (player == 0) ? 'X' : 'O';
        printf("Player %d (%c), enter row and column (1-3 1-3): ", player+1, mark);
        scanf("%d %d", &row, &col);
        row--; col--;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row][col] = mark;
        if (checkWin()) {
            printBoard();
            printf("Player %d (%c) wins!\n", player+1, mark);
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        player = 1 - player;
    }
    return 0;
}
