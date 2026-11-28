import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    V, E = int(d[0]), int(d[1])
    adj = {i: [] for i in range(V)}
    idx = 2
    for _ in range(E):
        u, v = int(d[idx]), int(d[idx+1])
        adj[u].append(v)
        adj[v].append(u)
        idx += 2
    M = int(d[idx])
    colors = [0] * V
    def rec(v):
        if v == V: return True
        for c in range(1, M + 1):
            if all(colors[nei] != c for nei in adj[v]):
                colors[v] = c
                if rec(v + 1): return True
                colors[v] = 0
        return False
    print("true" if rec(0) else "false")
solve()
