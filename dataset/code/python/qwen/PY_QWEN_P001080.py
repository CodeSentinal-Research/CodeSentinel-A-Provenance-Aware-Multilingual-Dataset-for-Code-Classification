import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    disc = [0] * (n+1)
    low = [0] * (n+1)
    timer = [1]
    ap = set()
    
    def dfs(u, parent):
        disc[u] = low[u] = timer[0]
        timer[0] += 1
        children = 0
        for v in adj[u]:
            if v == parent:
                continue
            if disc[v] == 0:
                children += 1
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if parent == -1 and children > 1:
                    ap.add(u)
                if parent != -1 and low[v] >= disc[u]:
                    ap.add(u)
            else:
                low[u] = min(low[u], disc[v])
                
    for i in range(1, n+1):
        if disc[i] == 0:
            dfs(i, -1)
            
    if not ap:
        print("NONE")
    else:
        print(*sorted(ap))

if __name__ == "__main__":
    solve()

