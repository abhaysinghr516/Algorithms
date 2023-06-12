package main

import "fmt"

func floodFill(screen [][]int, x int, y int, prevColor int, newColor int) {
    if x < 0 || x >= len(screen) || y < 0 || y >= len(screen[0]) || screen[x][y] != prevColor {
        return
    }

    screen[x][y] = newColor

    floodFill(screen, x+1, y, prevColor, newColor)
    floodFill(screen, x-1, y, prevColor, newColor)
    floodFill(screen, x, y+1, prevColor, newColor)
    floodFill(screen, x, y-1, prevColor, newColor)
}

func main() {
    screen := [][]int{
        {1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 2, 2, 2, 1, 0},
        {1, 1, 1, 2, 2, 2, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
    }

    x := 4
    y := 4
    prevColor := 2
    newColor := 3
    floodFill(screen, x, y, prevColor, newColor)

    for _, row := range screen {
        fmt.Println(row)
    }
}
