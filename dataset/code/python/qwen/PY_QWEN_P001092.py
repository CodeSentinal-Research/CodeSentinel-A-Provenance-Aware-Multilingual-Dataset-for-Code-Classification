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
                
    for k in range(1, LOG):
        for i in range(1, n+1):
            if parent[k-1][i] != -1:
                parent[k][i] = parent[k-1][parent[k-1][i]]
                
    def kth_ancestor(node, k):
        for i in range(LOG):
            if k & (1 << i):
                node = parent[i][node]
                if node == -1:
                    return -1
        return node
        
    output = []
    for _ in range(q):
        node = int(input_data[idx]); idx += 1
        k = int(input_data[idx]); idx += 1
        output.append(str(kth_ancestor(node, k)))
        
    print("
".join(output))

if __name__ == "__main__":
    solve()

