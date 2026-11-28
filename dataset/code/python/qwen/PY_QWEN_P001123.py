import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    threshold = int(input_data[idx]); idx += 1
    
    dist = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dist[i][i] = 0
        
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        w = int(input_data[idx]); idx += 1
        dist[u][v] = min(dist[u][v], w)
        dist[v][u] = min(dist[v][u], w)
        
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                    
    min_reachable = n + 1
    best_city = -1
    for i in range(1, n + 1):
        count = sum(1 for j in range(1, n + 1) if i != j and dist[i][j] <= threshold)
        if count <= min_reachable:
            min_reachable = count
            best_city = i
            
    print(best_city)

if __name__ == "__main__":
    solve()

