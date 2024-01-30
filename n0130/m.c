#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for rand()

#define WIDTH 48
#define HEIGHT 48

typedef struct {
    int x;
    int y;
    bool n;
    bool e;
    bool w;
    bool s;
    bool visited; // Added for tracking visited cells
    const char* color;
} Cell;

typedef struct {
    Cell table[WIDTH * HEIGHT];
} Maze;

// Function to get a random number between min and max
int getRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to check neighbors of a cell
void checkNeighbors(Cell* cell, Maze* maze, Cell** neighbors) {
    int x = cell->x;
    int y = cell->y;

    // Initialize the neighbors array
    for (int i = 0; i < 4; ++i) {
        neighbors[i] = NULL;
    }

    // Check north neighbor
    if (y > 0 && !maze->table[(y - 1) * WIDTH + x].visited) {
        neighbors[0] = &maze->table[(y - 1) * WIDTH + x];
    }

    // Check east neighbor
    if (x < WIDTH - 1 && !maze->table[y * WIDTH + (x + 1)].visited) {
        neighbors[1] = &maze->table[y * WIDTH + (x + 1)];
    }

    // Check south neighbor
    if (y < HEIGHT - 1 && !maze->table[(y + 1) * WIDTH + x].visited) {
        neighbors[2] = &maze->table[(y + 1) * WIDTH + x];
    }

    // Check west neighbor
    if (x > 0 && !maze->table[y * WIDTH + (x - 1)].visited) {
        neighbors[3] = &maze->table[y * WIDTH + (x - 1)];
    }
}


// Function to remove walls between two cells
void removeWalls(Cell* current, Cell* neighbor) {
    int xDiff = current->x - neighbor->x;
    int yDiff = current->y - neighbor->y;

    // Remove the walls between the current cell and its neighbor
    if (xDiff == 1) { // Neighbor is to the left (west)
        current->w = false;
        neighbor->e = false;
    } else if (xDiff == -1) { // Neighbor is to the right (east)
        current->e = false;
        neighbor->w = false;
    } else if (yDiff == 1) { // Neighbor is above (north)
        current->n = false;
        neighbor->s = false;
    } else if (yDiff == -1) { // Neighbor is below (south)
        current->s = false;
        neighbor->n = false;
    }
}


// Function for depth-first search maze generation
void dfs(Cell* cell, Maze* maze) {
    if (!cell) return;

    cell->visited = true;

    Cell* neighbors[4]; // Assuming a maximum of 4 neighbors (north, east, west, south)
    checkNeighbors(cell, maze, neighbors);

    for (int i = 0; i < 4 && neighbors[i] != NULL; ++i) {
        if (!neighbors[i]->visited) {
            // Assuming vis is a global array for tracking visited cells
            // It's not explicitly declared in your JavaScript code, so you may need to add it
            // If vis is a global array, you should replace it with the 'maze' parameter in C
            // vis.push(cell); // Not needed in C, as 'cell->visited' is already updated
            Cell* n = neighbors[getRandom(0, i)]; // Randomly select a neighbor
            removeWalls(cell, n);
            dfs(n, maze);
            // Assuming vis is a global array, you should replace it with the 'maze' parameter in C
            // vis.push(n); // Not needed in C, as 'n->visited' is already updated
        }
    }
}

// Function to generate the maze
void generateMaze(Maze* maze) {
    // Assuming starting cell is at index 0 in the 'table' array
    dfs(&maze->table[0], maze);
}

// Function to print the maze in the specified format
void printMaze(const Maze* maze) {
    printf("{\"table\": [\n");

    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        const Cell* cell = &maze->table[i];
        printf("  {\"x\": %d, \"y\": %d, \"n\": %s, \"e\": %s, \"w\": %s, \"s\": %s, \"color\": \"%s\"}%s\n",
               cell->x, cell->y,
               cell->n ? "true" : "false", cell->e ? "true" : "false",
               cell->w ? "true" : "false", cell->s ? "true" : "false",
               cell->color,
               (i == WIDTH * HEIGHT - 1) ? "" : ",");
    }

    printf("]}\n");
}

int main() {
    Maze maze;
    generateMaze(&maze);
    printMaze(&maze);

    return 0;
}
