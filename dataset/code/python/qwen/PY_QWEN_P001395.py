import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    points = []
    idx = 1
    for _ in range(n):
        x = int(input_data[idx]); idx += 1
        y = int(input_data[idx]); idx += 1
        points.append((x, y))
        
    boomerangs = 0
    for i in range(n):
        dist_count = defaultdict(int)
        for j in range(n):
            if i == j:
                continue
            dx = points[i][0] - points[j][0]
            dy = points[i][1] - points[j][1]
            dist_sq = dx*dx + dy*dy
            dist_count[dist_sq] += 1
            
        for count in dist_count.values():
            boomerangs += count * (count - 1)
            
    print(boomerangs)

solve()

