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
        row = list(map(int, input_data[idx:idx+c]))
        idx += c
        grid.append(row)
        
    visited = [[False] * c for _ in range(r)]
    count = 0
    
    def bfs(sr, sc):
        q = deque([(sr, sc)])
        visited[sr][sc] = True
        while q:
            ur, uc = q.popleft()
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = ur + dr, uc + dc
                if 0 <= nr < r and 0 <= nc < c and not visited[nr][nc] and grid[nr][nc] == 1:
                    visited[nr][nc] = True
                    q.append((nr, nc))
                    
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 1 and not visited[i][j]:
                bfs(i, j)
                count += 1
                
    print(count)

if __name__ == "__main__":
    solve()

