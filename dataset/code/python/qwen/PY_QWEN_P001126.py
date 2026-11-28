import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(list(map(int, input_data[idx:idx+c])))
        idx += c
        
    # Dijkstra variant: minimize max difference
    dist = [[float('inf')] * c for _ in range(r)]
    dist[0][0] = 0
    heap = [(0, 0, 0)] # effort, r, c
    
    while heap:
        effort, ur, uc = heapq.heappop(heap)
        if ur == r - 1 and uc == c - 1:
            print(effort)
            return
        if effort > dist[ur][uc]:
            continue
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = ur + dr, uc + dc
            if 0 <= nr < r and 0 <= nc < c:
                new_effort = max(effort, abs(grid[nr][nc] - grid[ur][uc]))
                if new_effort < dist[nr][nc]:
                    dist[nr][nc] = new_effort
                    heapq.heappush(heap, (new_effort, nr, nc))

if __name__ == "__main__":
    solve()

