Here is the Python code with the main function and input handling.

def count_paths(N, M, grid):
    if N == 1 or M == 1:
        return 1 if grid[0][0] == 1 else 0
    
    dp_table = [[0 for _ in range(M)] for _ in range(N)]
    
    dp_table[0][0] = 1 if grid[0][0] == 1 else 0
    
    for i in range(1, N):
        if grid[i][0] == 1:
            dp_table[i][0] = dp_table[i-1][0]
    
    for j in range(1, M):
        if grid[0][j] == 1:
            dp_table[0][j] = dp