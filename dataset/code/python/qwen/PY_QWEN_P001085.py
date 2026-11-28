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
    
    adj = [[] for _ in range(n+1)]
    in_degree = [0] * (n+1)
    
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        in_degree[v] += 1
        
    # Topological sort DP
    dp = [0] * (n+1)
    dp[s] = 1
    
    q = deque()
    for i in range(1, n+1):
        if in_degree[i] == 0:
            q.append(i)
            
    while q:
        u = q.popleft()
        for v in adj[u]:
            dp[v] += dp[u]
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)
                
    print(dp[t])

if __name__ == "__main__":
    solve()

