import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    x = abs(int(input_data[0]))
    y = abs(int(input_data[1]))
    if x == 0 and y == 0:
        print(0)
        return
    q = deque([((0, 0), 0)])
    vis = {(0, 0)}
    while q:
        (cx, cy), d = q.popleft()
        for dx, dy in [(1,2),(2,1),(-1,2),(-2,1),(1,-2),(2,-1),(-1,-2),(-2,-1)]:
            nx, ny = cx + dx, cy + dy
            if abs(nx) <= x + 2 and abs(ny) <= y + 2:
                if (nx, ny) not in vis:
                    if abs(nx) == x and abs(ny) == y:
                        print(d + 1)
                        return
                    vis.add((nx, ny))
                    q.append(((nx, ny), d + 1))
solve()
