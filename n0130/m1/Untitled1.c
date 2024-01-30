#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for rand()
#include <time.h>
#define WIDTH 5
#define HEIGHT 5
#define SVG_IDX_MARGEN 0
typedef struct
{
    int x;
    int y;
    bool n;
    bool e;
    bool w;
    bool s;
    bool visited; // Added for tracking visited cells
    const char* color;
} Cell;

typedef struct
{
    Cell table[WIDTH * HEIGHT];
} Maze;

// Function to get a random number between min and max
int getRandom(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Function to check neighbors of a cell
void checkNeighbors(Cell* cell, Maze* maze, Cell** neighbors)
{
    printf("\x1b[33;40mcheckNeighbors (%3d,%3d)\n\x1b[0m",cell->x,cell->y);

    int x = cell->x;
    int y = cell->y;

    // Initialize the neighbors array
    for (int i = 0; i < 4; ++i)
    {
        neighbors[i] = NULL;
    }

    // Check north neighbor
    if (y > 0 && !maze->table[(y - 1) * WIDTH + x].visited)
    {
        neighbors[0] = &maze->table[(y - 1) * WIDTH + x];
    }

    // Check east neighbor
    if (x < WIDTH - 1 && !maze->table[y * WIDTH + (x + 1)].visited)
    {
        neighbors[1] = &maze->table[y * WIDTH + (x + 1)];
    }

    // Check south neighbor
    if (y < HEIGHT - 1 && !maze->table[(y + 1) * WIDTH + x].visited)
    {
        neighbors[2] = &maze->table[(y + 1) * WIDTH + x];
    }

    // Check west neighbor
    if (x > 0 && !maze->table[y * WIDTH + (x - 1)].visited)
    {
        neighbors[3] = &maze->table[y * WIDTH + (x - 1)];
    }
}


// Function to remove walls between two cells
void removeWalls(Cell* current, Cell* neighbor)
{
    int xDiff = current->x - neighbor->x;
    int yDiff = current->y - neighbor->y;

    // Remove the walls between the current cell and its neighbor
    if (xDiff == 1)   // Neighbor is to the left (west)
    {
        current->w = false;
        neighbor->e = false;
    }
    else if (xDiff == -1)     // Neighbor is to the right (east)
    {
        current->e = false;
        neighbor->w = false;
    }
    else if (yDiff == 1)     // Neighbor is above (north)
    {
        current->n = false;
        neighbor->s = false;
    }
    else if (yDiff == -1)     // Neighbor is below (south)
    {
        current->s = false;
        neighbor->n = false;
    }
}


// Function for depth-first search maze generation
void dfs(Cell* cell, Maze* maze)
{
    printf("\x1b[33;40mdfs (%3d,%3d)\n\x1b[0m",cell->x,cell->y);
    if (!cell) return;

    cell->visited = true;

    Cell* neighbors[4]; // Assuming a maximum of 4 neighbors (north, east, west, south)
    checkNeighbors(cell, maze, neighbors);
    if((neighbors[0]==NULL)&&(neighbors[1]==NULL)&&(neighbors[2]==NULL)&&(neighbors[3]==NULL))
    {
        printf("\t\tskip!\n");
    }
    else
    {
        int r = getRandom(0, 3);
        Cell* n = neighbors[r]; // Randomly select a neighbor
        while (n==NULL)
        {
            r = getRandom(0, 3);
            n = neighbors[r];
        }
        removeWalls(cell, n);
        dfs(n, maze);
    }
}

// Function to generate the maze
void generateMaze(Maze* maze)
{
    // Assuming starting cell is at index 0 in the 'table' array
    dfs(&maze->table[0], maze);
}

// Function to print the maze in the specified format
void printMaze(const Maze* maze)
{
    printf("{\"table\": [\n");

    for (int i = 0; i < WIDTH * HEIGHT; ++i)
    {
        const Cell* cell = &maze->table[i];
        printf("  {\"x\": %d, \"y\": %d, \"n\": %s, \"e\": %s, \"w\": %s, \"s\": %s, \"color\": \"%s\"}%s\n",
               cell->x+SVG_IDX_MARGEN, cell->y+SVG_IDX_MARGEN,
               cell->n ? "True" : "False", cell->e ? "True" : "False",
               cell->w ? "True" : "False", cell->s ? "True" : "False",
               cell->color,
               (i == WIDTH * HEIGHT - 1) ? "" : ",");
    }

    printf("]}\n");
}

Maze initMaze()
{
    Maze maze;
    for(int j = 0 ; j < HEIGHT; j++)
    {
        for(int i = 0 ; i < WIDTH; i++)
        {
            maze.table[j*HEIGHT+i].x=i;
            maze.table[j*HEIGHT+i].y=j;
            maze.table[j*HEIGHT+i].n=true;
            maze.table[j*HEIGHT+i].e=true;
            maze.table[j*HEIGHT+i].w=true;
            maze.table[j*HEIGHT+i].s=true;
            maze.table[j*HEIGHT+i].visited=false;
            maze.table[j*HEIGHT+i].color="green";
        }
    }
    return maze;
}

int main()
{
    srand(time(NULL));
    Maze maze = initMaze();
    generateMaze(&maze);
    printMaze(&maze);

    return 0;
}

