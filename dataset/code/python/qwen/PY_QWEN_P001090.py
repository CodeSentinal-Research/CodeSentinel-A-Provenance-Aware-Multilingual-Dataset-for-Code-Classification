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
    
    print(dist_v[v])

if __name__ == "__main__":
    solve()

