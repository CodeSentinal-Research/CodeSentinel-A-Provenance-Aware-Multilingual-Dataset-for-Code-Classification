Here is a Python code snippet for the problem:

def unique_paths(R, C):
    paths = [[0 for _ in range(C)] for _ in range(R)]

    if R > 0 and C > 0 and grid[0][0] == 1:
        paths[0][0] = 0
    else:
        paths[0][0] = 1

    for j in range(1, C):
        if paths[0][j-1] == 1:
            paths[0][j] = 0
        else:
            paths[0][j] = paths[0][j-1]

    for i in range(1, R):
        if paths[i-1][0] == 1:
            paths[i][0] = 0
        else:
            paths[i][0] = paths[i-1][0]

    for i in range(1, R):
        for j in range(1, C):
            if grid[i][j] == 1:
                paths[i][j] = 0
            else:
                paths[i][j] = paths[i-1][j] + paths[i][j-1]

    return paths[-1][-1]

if __name__ == '__main__':
    R, C = map(int, input().split())
    grid = [[0 for _ in range(C)] for _ in range(R)]
    for i in range(R):
        row = list(map(int, input().split()))
        for j in range(C):
            grid[i][j] = row[j]
    print(unique_paths(R, C))

In the above code, we first initialize a 2D array `paths` of size `R x C` filled with zeros. Then, we fill this array according to the rules of the problem: for each cell, if the cell is an obstacle (i.e., having a value of 1), then the number of paths is zero; otherwise, the number of paths is equal to the sum of the paths from the top cell (i.e., `paths[0][j-1]`) and the left cell (i.e., `paths[i-1][0]`). After filling up this array, we return the bottom-right cell from the `paths` array, which contains the number of unique paths.