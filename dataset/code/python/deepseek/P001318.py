Here is a Python code for the problem:

def can_word_fit(R, C, grid, word):
    rows, cols = len(grid), len(grid[0])
    visited = [[False]*cols for _ in range(rows)]
    
    def dfs(i, j, k):
        if k == len(word):
            return True
        if i < 0 or i >= rows or j < 0 or j >= cols or visited[i][j] or grid[i][j] != word[k]:
            return False
        visited[i][j] = True
        if dfs(i+1, j, k+1) or dfs(i-1, j, k+1) or dfs(i, j+1, k+1) or dfs(i, j-1, k+1):
            return True
        visited[i][j] = False
        return False
    
    for i in range(rows):
        for j in range(cols):
            if dfs(i, j, 0):
                return 'YES'
    return 'NO'

R, C = map(int, input().split())
grid = [input().split() for _ in range(R)]
word = input()
print(can_word_fit(R, C, grid, word))

In this code, we use Depth-First Search (DFS) to check if we can fit the word on the grid. We check all adjacent cells (up, down, left, and right) to see if we can fit the next character of the word. If we find a cell that can be visited, we continue the DFS from there. If we cannot find any adjacent cells that can be visited, we backtrack and mark the cell as not visited.