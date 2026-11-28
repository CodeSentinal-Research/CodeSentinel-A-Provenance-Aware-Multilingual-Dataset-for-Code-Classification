def numIslands(grid):
    def dfs(i, j):
        if i<0 or i>=len(grid) or j<0 or j>=len(grid[0]):
            return
        if grid[i][j] == '0':
            return
        grid[i][j] = '0'
        dfs(i+1, j)
        dfs(i-1, j)
        dfs(i, j+1)
        dfs(i, j-1)

    count = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1':
                dfs(i, j)
                count += 1
    return count

def main():
    R, C = map(int, input().split())
    grid = [input() for _ in range(R)]
    print(numIslands(grid))

if __name__ == "__main__":
    main()

This code defines a function `numIslands` that takes a 2D grid as input and returns the number of islands in the grid. It uses Depth First Search (DFS) to count the number of connected islands.

The function `main` handles the input and output. It first reads the number of rows and columns from the input, then reads the grid from the input. It then calls `numIslands` with the grid and prints the result.

The `numIslands` function works by performing DFS on each cell in the grid. If a cell is '1' (representing land), it marks the cell as '0' (representing water), then recursively calls dfs on its four neighbors.

The `main` function uses `map` to convert the input to integers, and `input` to read the input. It then calls `main`.