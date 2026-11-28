import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
        
    if grid[0][0] == 1 or grid[n-1][n-1] == 1:
        print(-1)
        return
        
    q = deque([(0, 0, 1)])
    grid[0][0] = 1 # Mark visited
    
    while q:
        r, c, dist = q.popleft()
        if r == n - 1 and c == n - 1:
            print(dist)
            return
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                if dr == 0 and dc == 0: continue
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    grid[nr][nc] = 1
                    q.append((nr, nc, dist + 1))
                    
    print(-1)

if __name__ == "__main__":
    solve()

