#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int matrix[MAX_SIZE][MAX_SIZE];
int m, n;

// Check if a given position is valid
bool isValid(int row, int col) {
    return (row >= 0 && row < m && col >= 0 && col < n && matrix[row][col] == 1);
}

// Recursive function to find the shortest path
bool findPath(int row, int col, int pathLength) {
    // If the destination is reached
    if (row == m - 1 && col == n - 1) {
        printf("Shortest Path Length: %d\n", pathLength);
        return true;
    }

    // Mark the current cell as visited
    matrix[row][col] = 2; // Marked as visited

    // Check all four possible directions: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (isValid(newRow, newCol)) {
            if (findPath(newRow, newCol, pathLength + 1)) {
                return true;
            }
        }
    }

    // No path found through this cell, backtrack
    matrix[row][col] = 1; // Reset the cell to allow other paths

    return false;
}

int main() {
    printf("Enter the number of rows (m) and columns (n) for the matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix (0 for wall, 1 for path):\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (matrix[0][0] == 0 || matrix[m - 1][n - 1] == 0) {
        printf("No valid path exists.\n");
    } else {
        if (!findPath(0, 0, 0)) {
            printf("No valid path exists.\n");
        }
    }

    return 0;
}

