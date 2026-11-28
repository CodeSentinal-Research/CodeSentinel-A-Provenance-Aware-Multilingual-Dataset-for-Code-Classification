Here is the Python code for the problem:

def minPathSum(grid):
    r = len(grid)
    c = len(grid[0])

    for i in range(1, c):
        grid[0][i] += grid[0][i-1]

    for i in range(1, r):
        grid[i][0] += grid[i-1][0]

    for i in range(1, r):
        for j in range(1, c):
            grid[i][j] += min(grid[i-1][j], grid[i][j-1])

    return grid[-1][-1]

r = int(input().strip())
grid = []
for i in range(r):
    row = list(map(int, input().strip().split()))
    grid.append(row)

print(minPathSum(grid))

This code first initializes the first row and the first column of the grid. Then, it iterates over the rest of the grid and updates each cell with the minimum sum of its left and up neighbors. The minimum path sum is at the bottom-right corner of the grid. The input handling part reads the grid from the user and prints the minimum path sum.