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
    fresh_count = 0
    q = deque()
    
    for i in range(r):
        row = list(map(int, input_data[idx:idx+c]))
        idx += c
        grid.append(row)
        for j in range(c):
            if row[j] == 1:
                fresh_count += 1
            elif row[j] == 2:
                q.append((i, j, 0))
                
    if fresh_count == 0:
        print(0)
        return
        
    minutes = 0
    directions = [(1,0), (-1,0), (0,1), (0,-1)]
    
    while q:
        ur, uc, time = q.popleft()
        minutes = time
        for dr, dc in directions:
            nr, nc = ur + dr, uc + dc
            if 0 <= nr < r and 0 <= nc < c and grid[nr][nc] == 1:
                grid[nr][nc] = 2
                fresh_count -= 1
                q.append((nr, nc, time + 1))
                
    print(minutes if fresh_count == 0 else -1)

if __name__ == "__main__":
    solve()

