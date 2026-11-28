import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    # Find diameter endpoints
    def bfs(start):
        dist = [-1] * (n+1)
        q = deque([start])
        dist[start] = 0
        last_node = start
        while q:
            u = q.popleft()
            last_node = u
            for v in adj[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    q.append(v)
        return last_node, dist
        
    u, _ = bfs(1)
    v, dist_v = bfs(u)
    
    # Centers are middle nodes of diameter path
    diameter = dist_v[v]
    centers = []
    
    # Reconstruct path or just find nodes with eccentricity = radius
    # Radius = ceil(diameter / 2)
    # Center nodes are those with max distance to any node = radius
    
    # Simpler: Peel leaves layer by layer
    degree = [len(adj[i]) for i in range(n+1)]
    leaves = deque([i for i in range(1, n+1) if degree[i] <= 1])
    remaining = n
    while remaining > 2:
        leaf_count = len(leaves)
        remaining -= leaf_count
        for _ in range(leaf_count):
            u = leaves.popleft()
            for v in adj[u]:
                degree[v] -= 1
                if degree[v] == 1:
                    leaves.append(v)
                    
    print(*sorted(leaves))

if __name__ == "__main__":
    solve()

