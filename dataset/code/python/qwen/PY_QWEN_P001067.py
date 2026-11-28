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
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    visited = [False] * (n+1)
    q = deque([s])
    visited[s] = True
    count = 0
    
    while q:
        u = q.popleft()
        count += 1
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)
                
    print(count)

if __name__ == "__main__":
    solve()

