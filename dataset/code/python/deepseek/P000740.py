Here is the python code for the problem. The main idea is to use Depth-First Search (DFS) algorithm. DFS is an algorithm for traversing or searching tree or graph data structures. In this case, the graph is a maze.

def dfs(grid, x, y, n, m, path=''):
    if x == n-1 and y == m-1:
        print(path)
        return
    if x == n-1:
        dfs(grid, x, y+1, n, m, path+str(grid[x][y]))
    else:
        dfs(grid, x+1, y, n, m, path+str(grid[x][y]))
        dfs(grid, x+1, y+1, n, m, path+str(grid[x][y]))
        dfs(grid, x, y+1, n, m, path+str(grid[x][y]))

def main():
    n = int(input("Enter N: "))
    m = int(input("Enter M: "))
    grid = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            grid[i][j] = i+j+1
    dfs(grid, 0, 0, n, m)

if __name__ == "__main__":
    main()

The main function handles the input of N and M and creates a grid of all possible paths. Then, it uses DFS to find all the paths. The base cases for DFS are when x and y are both N-1 and M-1, in which case it prints the path. If not, it continues to call DFS for right and downward steps, then diagonally down-right steps.

This code handles the input of N and M in the same way as in the problem statement. Note that the grid in the code is created as if the maze is filled with integers starting from 1, with 1 representing the top left cell and N*M representing the bottom right cell.

Please ensure you run this code in a Python environment.