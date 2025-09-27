function floodFill(screen, x, y, prevColor, newColor) {
    if (x < 0 || x >= screen.length || y < 0 || y >= screen[0].length || screen[x][y] !== prevColor) {
        return;
    }

    screen[x][y] = newColor;

    floodFill(screen, x + 1, y, prevColor, newColor);
    floodFill(screen, x - 1, y, prevColor, newColor);
    floodFill(screen, x, y + 1, prevColor, newColor);
    floodFill(screen, x, y - 1, prevColor, newColor);
}

const screen = [
    [1, 1, 1, 1, 0, 0, 1, 1],
    [1, 1, 1, 1, 0, 0, 1, 1],
    [1, 0, 0, 1, 1, 1, 1, 1],
    [1, 2, 2, 2, 2, 2, 2, 1],
    [1, 1, 1, 2, 2, 2, 1, 0],
    [1, 1, 1, 2, 2, 2, 1, 0],
    [1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 0],
];

const x = 4;
const y = 4;
const prevColor = 2;
const newColor = 3;
floodFill(screen, x, y, prevColor, newColor);

console.log(screen);
