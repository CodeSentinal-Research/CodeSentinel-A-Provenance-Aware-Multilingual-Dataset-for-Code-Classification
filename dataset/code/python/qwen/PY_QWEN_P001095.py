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
    t = int(input_data[idx]); idx += 1
    
    capacity = [[0] * (n+1) for _ in range(n+1)]
    adj = [[] for _ in range(n+1)]
    
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        c = int(input_data[idx]); idx += 1
        capacity[u][v] += c
        adj[u].append(v)
        adj[v].append(u)
        
    def bfs():
        parent = [-1] * (n+1)
        parent[s] = -2
        q = deque([(s, float('inf'))])
        while q:
            u, flow = q.popleft()
            for v in adj[u]:
                if parent[v] == -1 and capacity[u][v] > 0:
                    parent[v] = u
                    new_flow = min(flow, capacity[u][v])
                    if v == t:
                        return new_flow, parent
                    q.append((v, new_flow))
        return 0, parent
        
    max_flow = 0
    while True:
        flow, parent = bfs()
        if flow == 0:
            break
        max_flow += flow
        v = t
        while v != s:
            u = parent[v]
            capacity[u][v] -= flow
            capacity[v][u] += flow
            v = u
            
    print(max_flow)

if __name__ == "__main__":
    solve()

