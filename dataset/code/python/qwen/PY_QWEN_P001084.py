import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[False] * (n+1) for _ in range(n+1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u][v] = True
        adj[v][u] = True
        
    visited = [False] * (n+1)
    
    def dfs(u, count):
        if count == n:
            return adj[u][1] # Check if cycle closes
        visited[u] = True
        for v in range(1, n+1):
            if adj[u][v] and not visited[v]:
                if dfs(v, count+1):
                    return True
        visited[u] = False
        return False
        
    print("YES" if dfs(1, 1) else "NO")

if __name__ == "__main__":
    solve()

