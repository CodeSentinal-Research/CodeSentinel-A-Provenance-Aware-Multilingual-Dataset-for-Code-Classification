import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    s = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    weights = [[] for _ in range(n+1)]
    in_degree = [0] * (n+1)
    
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        w = int(input_data[idx]); idx += 1
        adj[u].append(v)
        weights[u].append(w)
        in_degree[v] += 1
        
    # Topological sort
    q = deque()
    for i in range(1, n+1):
        if in_degree[i] == 0:
            q.append(i)
            
    topo_order = []
    while q:
        u = q.popleft()
        topo_order.append(u)
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)
                
    dist = [float('inf')] * (n+1)
    dist[s] = 0
    
    for u in topo_order:
        if dist[u] != float('inf'):
            for i, v in enumerate(adj[u]):
                if dist[v] > dist[u] + weights[u][i]:
                    dist[v] = dist[u] + weights[u][i]
                    
    result = []
    for i in range(1, n+1):
        if dist[i] == float('inf'):
            result.append("-1")
        else:
            result.append(str(dist[i]))
            
    print(" ".join(result))

if __name__ == "__main__":
    solve()

