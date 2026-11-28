import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    LOG = math.ceil(math.log2(n)) + 1
    parent = [[-1] * (n+1) for _ in range(LOG)]
    depth = [0] * (n+1)
    
    # BFS to fill parent[0] and depth
    from collections import deque
    q_bfs = deque([1])
    visited = [False] * (n+1)
    visited[1] = True
    while q_bfs:
        u = q_bfs.popleft()
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                parent[0][v] = u
                depth[v] = depth[u] + 1
                q_bfs.append(v)
                
    # Binary lifting table
    for k in range(1, LOG):
        for i in range(1, n+1):
            if parent[k-1][i] != -1:
                parent[k][i] = parent[k-1][parent[k-1][i]]
                
    def lca(a, b):
        if depth[a] < depth[b]:
            a, b = b, a
        # Lift a to same depth as b
        diff = depth[a] - depth[b]
        for k in range(LOG):
            if diff & (1 << k):
                a = parent[k][a]
        if a == b:
            return a
        for k in range(LOG-1, -1, -1):
            if parent[k][a] != parent[k][b]:
                a = parent[k][a]
                b = parent[k][b]
        return parent[0][a]
        
    output = []
    for _ in range(q):
        a = int(input_data[idx]); idx += 1
        b = int(input_data[idx]); idx += 1
        output.append(str(lca(a, b)))
        
    print("
".join(output))

if __name__ == "__main__":
    solve()

