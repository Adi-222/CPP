// LAB Assignment 8
// Using BAcktracking approach write a c program to solve 8 queens problem



#include <stdio.h>
#include <stdbool.h>

#define N 8

int counter = 0; 

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    counter++; // Increment counter for checking safety
    for (int i = 0; i < col; i++) {
        counter++;
        if (board[row][i]) return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        counter++;
        if (board[i][j]) return false;
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        counter++;
        if (board[i][j]) return false;
    }

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    counter++; // Increment counter for recursive call
    if (col >= N) return true;

    for (int i = 0; i < N; i++) {
        counter++;
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            counter++; // Increment counter for placing a queen

            if (solveNQUtil(board, col + 1)) return true;

            board[i][col] = 0;
            counter++; // Increment counter for backtracking
        }
    }

    return false;
}

void solveNQ() {
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        printf("Total number of operations: %d\n", counter);
        return;
    }

    printSolution(board);
    printf("Total number of operations: %d\n", counter);
}

int main() {
    solveNQ();
    return 0;
}
