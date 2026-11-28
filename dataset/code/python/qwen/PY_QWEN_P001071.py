import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    rev_adj = [[] for _ in range(n+1)]
    
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        rev_adj[v].append(u)
        
    # Find vertex with highest finish time in DFS (Kosaraju step 1 simplified)
    # Or simply try each vertex? No, O(N(N+M)).
    # Use Kosaraju or two-pass DFS.
    
    visited = [False] * (n+1)
    order = []
    
    def dfs1(u):
        stack = [(u, False)]
        while stack:
            node, processed = stack.pop()
            if processed:
                order.append(node)
                continue
            if visited[node]:
                continue
            visited[node] = True
            stack.append((node, True))
            for v in adj[node]:
                if not visited[v]:
                    stack.append((v, False))
                    
    for i in range(1, n+1):
        if not visited[i]:
            dfs1(i)
            
    candidate = order[-1]
    
    # Check if candidate can reach all others
    visited2 = [False] * (n+1)
    q = deque([candidate])
    visited2[candidate] = True
    count = 1
    while q:
        u = q.popleft()
        for v in adj[u]:
            if not visited2[v]:
                visited2[v] = True
                q.append(v)
                count += 1
                
    if count == n:
        print(candidate)
    else:
        print(-1)

if __name__ == "__main__":
    solve()

