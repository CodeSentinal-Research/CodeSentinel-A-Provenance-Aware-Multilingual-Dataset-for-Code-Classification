import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    l = int(input_data[idx]); idx += 1
    r = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(l+1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        
    match_r = [-1] * (r+1)
    
    def dfs(u, visited):
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                if match_r[v] == -1 or dfs(match_r[v], visited):
                    match_r[v] = u
                    return True
        return False
        
    matching = 0
    for u in range(1, l+1):
        visited = [False] * (r+1)
        if dfs(u, visited):
            matching += 1
            
    print(matching)

if __name__ == "__main__":
    solve()

