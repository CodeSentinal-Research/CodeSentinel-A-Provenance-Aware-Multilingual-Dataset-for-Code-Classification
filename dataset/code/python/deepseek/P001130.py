Here is a Python solution for the problem. The main idea is to use depth-first search (DFS) to explore the grid and find all the regions.

def regions_cut_by_slashes(grid):
    rows = len(grid)
    cols = len(grid[0])
    directions = [(1,0),(-1,0),(0,1),(0,-1)]

    def dfs(i, j):
        grid[i][j] = 0
        for dx, dy in directions:
            x, y = i + dx, j + dy
            if x < 0 or y < 0 or x >= rows or y >= cols or grid[x][y] == 0:
                continue
            dfs(x, y)

    count = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                dfs(i, j)
                count += 1
    return count

def main():
    N = int(input())
    grid = [[0]*N for _ in range(N)]
    for i in range(N):
        line = input().strip()
        for j in range(N):
            if line[j] == '/':
                if j < N-1 and grid[i][j+1] == 1:
                    grid[i][j+1] = 0
                if i < N-1 and grid[i+1][j] == 1:
                    grid[i+1][j] = 0
            elif line[j] == '\\':
                if j > 0 and grid[i][j-1] == 1:
                    grid[i][j-1] = 0
                if i > 0 and grid[i-1][j] == 1:
                    grid[i-1][j] = 0
            else:
                if j < N-1 and grid[i][j+1] == 0:
                    grid[i][j+1] = 1
                if i < N-1 and grid[i+1][j] == 0:
                    grid[i+1][j] = 1
                if j > 0 and grid[i][j-1] == 0:
                    grid[i][j-1] = 1
                if i > 0 and grid[i-1][j] == 0:
                    grid[i-1][j] = 1
    print(regions_cut_by_slashes(grid))

if __name__ == "__main__":
    main()
This program reads the grid from input, counts the regions and then prints the count. The grid is represented as a 2D list where each cell can contain a slash ('/'), backslash ('\\') or a blank space (' '). The main function initializes the grid, calls the `regions_cut_by_slashes` function and prints the result.