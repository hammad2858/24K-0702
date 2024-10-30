#include <stdio.h>
#include <ctype.h>

#define ROWS 5
#define COLS 5

void print_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char grid[ROWS][COLS], int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] != 'X';
}

void move_player(char grid[ROWS][COLS], int *row, int *col, char move) {
    int new_row = *row, new_col = *col;

    switch (toupper(move)) {
        case 'W':
            new_row--;
            break;
        case 'S':
            new_row++;
            break;
        case 'A':
            new_col--;
            break;
        case 'D':
            new_col++;
            break;
        default:
            printf("Invalid move.\n");
            return;
    }

    if (is_valid_move(grid, new_row, new_col)) {
        if (grid[new_row][new_col] == 'I') {
            printf("Item collected!\n");
            grid[new_row][new_col] = ' ';
        }
        grid[*row][*col] = ' ';
        grid[new_row][new_col] = 'P';
        *row = new_row;
        *col = new_col;
    } else {
        printf("Invalid move.\n");
    }
}

int main() {
    char grid[ROWS][COLS] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int player_row = 4, player_col = 4;

    while (1) {
        print_grid(grid);
        printf("Enter your move (W, A, S, D, Q to quit): ");

        char move;
        scanf(" %c", &move);

        if (move == 'Q') {
            break;
        }

        move_player(grid, &player_row, &player_col, move);
    }

    printf("Game over.\n");

    return 0;
}