import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    sources = list(map(int, input_data[idx:idx+k]))
    
    dist = [-1] * (n+1)
    q = deque()
    for s in sources:
        dist[s] = 0
        q.append(s)
        
    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
                
    result = []
    for i in range(1, n+1):
        result.append(str(dist[i]))
        
    print(" ".join(result))

if __name__ == "__main__":
    solve()

