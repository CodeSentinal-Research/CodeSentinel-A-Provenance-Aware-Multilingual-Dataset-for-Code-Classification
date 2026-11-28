import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    m = int(input_data[0])
    n = int(input_data[1])
    maze = []
    idx = 2
    for _ in range(m):
        maze.append(input_data[idx])
        idx += 1
    ent_r = int(input_data[idx])
    ent_c = int(input_data[idx+1])
    q = deque([(ent_r, ent_c, 0)])
    vis = {(ent_r, ent_c)}
    while q:
        x, y, d = q.popleft()
        if (x == 0 or x == m - 1 or y == 0 or y == n - 1) and (x != ent_r or y != ent_c):
            print(d)
            return
        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and maze[nx][ny] == '.' and (nx, ny) not in vis:
                vis.add((nx, ny))
                q.append((nx, ny, d + 1))
    print(-1)
solve()
