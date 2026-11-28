def surroundedRegions(grid):
    rows = len(grid)
    cols = len(grid[0])
    
    def dfs(r, c):
        if r < 0 or c < 0 or r >= rows or c >= cols or grid[r][c] != 'O':
            return
        grid[r][c] = 'T'
        dfs(r-1, c)
        dfs(r+1, c)
        dfs(r, c-1)
        dfs(r, c+1)
    
    for r in range(rows):
        dfs(r, 0)
        dfs(r, cols-1)
    for c in range(cols):
        dfs(0, c)
        dfs(rows-1, c)
    
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 'O':
                grid[r][c] = 'X'
            elif grid[r][c] == 'T':
                grid[r][c] = 'O'

    return grid

def main():
    R = int(input().strip())
    rows = []
    for i in range(R):
        row = input().strip()
        row = list(row)
        rows.append(row)

    print(surroundedRegions(rows))

if __name__ == '__main__':
    main()

In the provided Python code, I first define a function `surroundedRegions` that takes a 2D list `grid` as input, and then calls a helper function `dfs` to perform the depth-first search. The helper function `dfs` takes in a row and column index and marks the connected 'O' cells with 'T' before the main function `main` handles input and output.

The main function reads the number of rows `R`, then reads each row as a list of characters. It then calls `surroundedRegions` and prints the modified grid.