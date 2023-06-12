class FloodFill {
    private static int M = 8;
    private static int N = 8;

    private static void floodFillUtil(int[][] screen, int x, int y, int prevC, int newC) {
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

    public static void floodFill(int[][] screen, int x, int y, int newC) {
        int prevC = screen[x][y];
        floodFillUtil(screen, x, y, prevC, newC);
    }

    public static void main(String[] args) {
        int[][] screen = {{1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 0, 0},
                          {1, 0, 0, 1, 1, 0, 1, 1},
                          {1, 2, 2, 2, 2, 0, 1, 0},
                          {1, 1, 1, 2, 2, 0, 1, 0},
                          {1, 1, 1, 2, 2, 2, 2, 0},
                          {1, 1, 1, 1, 1, 2, 1, 1},
                          {1, 1, 1, 1, 1, 2, 2, 1}};
        int x = 4, y = 4, newC = 3;
        floodFill(screen, x, y, newC);
    }
}
