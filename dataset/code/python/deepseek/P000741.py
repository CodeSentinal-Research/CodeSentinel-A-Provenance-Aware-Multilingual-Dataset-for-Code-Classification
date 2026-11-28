Here is the Python code:

def find_paths(matrix, x, y, path=''):
    if x < 0 or y < 0 or x >= len(matrix) or y >= len(matrix[0]):
        return
    if matrix[x][y] == 0:
        return
    if x == len(matrix) - 1 and y == len(matrix[0]) - 1:
        print(path + 'B')
        return
    if x == len(matrix) - 1:
        print(path + 'R' + 'B')
        return
    if y == 0:
        print(path + 'D' + 'B')
        return
    if y == len(matrix[0]) - 1:
        print(path + 'R' + 'D')
        return
    matrix[x][y] = 0
    find_paths(matrix, x + 1, y, path + 'D')
    find_paths(matrix, x - 1, y, path + 'U')
    find_paths(matrix, x, y + 1, path + 'R')
    find_paths(matrix, x, y - 1, path + 'L')
    matrix[x][y] = 1

def main():
    N, M = map(int, input().split())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))
    find_paths(matrix, 0, 0)

if __name__ == "__main__":
    main()

This program will find all paths in the grid from the top left to the bottom right cell, moving Up, Down, Left, and Right but not revisiting any cell more than once in a path. It uses a depth-first search approach to find all paths.

The `find_paths` function is a recursive function that checks each direction (Up, Down, Left, and Right) and if the cell is blocked or out of bounds, it returns. If the cell is not blocked, it checks if it is at the bottom right or bottom left, or the top left or top right, and if so, it prints the path and returns. If the cell is not blocked and not at the bottom right or bottom left, it sets the cell to blocked, moves in that direction, and then unsets the cell to be considered for other paths. The `main` function handles the input and calls `find_paths` with the initial coordinates of the top left cell and the bottom right cell.