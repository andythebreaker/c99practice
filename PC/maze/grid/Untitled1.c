
#include <stdio.h>
#include <stdbool.h>

// Structure to represent a cell in the grid
struct Cell {
    int i, j; // Coordinates of the cell
    bool o;   // Content of the cell
    struct {
        bool n, e, w, s; // Walls in the north, east, west, and south directions
    } wall;
};

// Function to print the grid based on the provided JSON structure
void printGrid(struct Cell grid[], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i * cols + j].o) {
                printf(" o ");
            } else {
                printf("   ");
            }

            // Print walls
            if (grid[i * cols + j].wall.e) {
                printf("|");
            } else {
                printf(" ");
            }

            if (j == cols - 1) {
                printf("\n");
            }
        }

        // Print bottom walls
        for (int j = 0; j < cols; ++j) {
            if (grid[i * cols + j].wall.s) {
                printf("---");
            } else {
                printf("   ");
            }

            if (j == cols - 1) {
                printf("\n");
            } else {
                if (grid[i * cols + j].wall.s || grid[i * cols + j + 1].wall.s) {
                    printf("+");
                } else {
                    printf(" ");
                }
            }
        }
    }
}

int main() {
    // Your JSON data
    struct Cell grid[] = {
        {0, 0, true, {true, false, false, true}},
        {0, 1, true, {false, true, false, true}},
        {0, 2, true, {true, false, true, false}},
        {1, 0, true, {false, false, true, true}},
        {1, 1, true, {true, true, true, true}},
        {1, 2, true, {false, true, true, false}},
        {2, 0, true, {true, false, false, true}},
        {2, 1, true, {false, true, false, false}},
        {2, 2, true, {true, false, true, true}},
    };

    int rows = 3;
    int cols = 3;

    // Print the grid
    printGrid(grid, rows, cols);

    return 0;
}
