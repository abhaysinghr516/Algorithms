#include <iostream>
#define M 8
#define N 8

void floodFillUtil(int screen[M][N], int x, int y, int prevC, int newC) {
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    screen[x][y] = newC;
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[M][N], int x, int y, int newC) {
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}

int main() {
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1}};
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC);
    return 0;
}
