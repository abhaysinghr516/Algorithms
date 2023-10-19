def flood_fill(screen, x, y, prev_color, new_color):
    if x < 0 or x >= len(screen) or y < 0 or y >= len(screen[0]) or screen[x][y] != prev_color:
        return

    screen[x][y] = new_color

    flood_fill(screen, x + 1, y, prev_color, new_color)
    flood_fill(screen, x - 1, y, prev_color, new_color)
    flood_fill(screen, x, y + 1, prev_color, new_color)
    flood_fill(screen, x, y - 1, prev_color, new_color)

screen = [
    [1, 1, 1, 1, 0, 0, 1, 1],
    [1, 1, 1, 1, 0, 0, 1, 1],
    [1, 0, 0, 1, 1, 1, 1, 1],
    [1, 2, 2, 2, 2, 2, 2, 1],
    [1, 1, 1, 2, 2, 2, 1, 0],
    [1, 1, 1, 2, 2, 2, 1, 0],
    [1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 0],
]

x = 4
y = 4
prev_color = 2
new_color = 3
flood_fill(screen, x, y, prev_color, new_color)

for row in screen:
    print(row)
