import sys

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
            
    visited2 = [False] * (n+1)
    scc_count = 0
    
    def dfs2(u):
        stack = [u]
        visited2[u] = True
        while stack:
            node = stack.pop()
            for v in rev_adj[node]:
                if not visited2[v]:
                    visited2[v] = True
                    stack.append(v)
                    
    for u in reversed(order):
        if not visited2[u]:
            dfs2(u)
            scc_count += 1
            
    print(scc_count)

if __name__ == "__main__":
    solve()

