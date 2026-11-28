import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    dist = [[float('inf')] * (n+1) for _ in range(n+1)]
    
    for i in range(1, n+1):
        dist[i][i] = 0
        
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        w = int(input_data[idx]); idx += 1
        dist[u][v] = min(dist[u][v], w)
        dist[v][u] = min(dist[v][u], w)
        
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
                    
    for i in range(1, n+1):
        row = []
        for j in range(1, n+1):
            if dist[i][j] == float('inf'):
                row.append("-1")
            else:
                row.append(str(dist[i][j]))
        print(" ".join(row))

if __name__ == "__main__":
    solve()

