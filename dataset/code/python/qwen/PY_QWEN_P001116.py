import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(list(input_data[idx])); idx += 1
        
    # Mark 'O's connected to boundary as safe ('S')
    q = deque()
    for i in range(r):
        for j in range(c):
            if (i == 0 or i == r - 1 or j == 0 or j == c - 1) and grid[i][j] == 'O':
                grid[i][j] = 'S'
                q.append((i, j))
                
    while q:
        ur, uc = q.popleft()
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = ur + dr, uc + dc
            if 0 <= nr < r and 0 <= nc < c and grid[nr][nc] == 'O':
                grid[nr][nc] = 'S'
                q.append((nr, nc))
                
    # Flip remaining 'O' to 'X', revert 'S' to 'O'
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 'O':
                grid[i][j] = 'X'
            elif grid[i][j] == 'S':
                grid[i][j] = 'O'
                
    for row in grid:
        print("".join(row))

if __name__ == "__main__":
    solve()

