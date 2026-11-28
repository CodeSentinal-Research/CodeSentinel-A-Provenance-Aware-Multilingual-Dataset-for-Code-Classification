import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    s = int(input_data[idx]); idx += 1
    
    edges = []
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        w = int(input_data[idx]); idx += 1
        edges.append((u, v, w))
        
    dist = [float('inf')] * (n+1)
    dist[s] = 0
    
    for _ in range(n-1):
        updated = False
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                updated = True
        if not updated:
            break
            
    # Check negative cycle
    for u, v, w in edges:
        if dist[u] != float('inf') and dist[v] > dist[u] + w:
            print("NEGATIVE CYCLE")
            return
            
    result = []
    for i in range(1, n+1):
        if dist[i] == float('inf'):
            result.append("-1")
        else:
            result.append(str(dist[i]))
            
    print(" ".join(result))

if __name__ == "__main__":
    solve()

