import sys
import heapq

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
        w = int(input_data[idx]); idx += 1
        adj[u].append((w, v))
        adj[v].append((w, u))
        
    visited = [False] * (n+1)
    heap = [(0, 1)] # Start from node 1
    total_weight = 0
    count = 0
    
    while heap and count < n:
        w, u = heapq.heappop(heap)
        if visited[u]:
            continue
        visited[u] = True
        total_weight += w
        count += 1
        for weight, v in adj[u]:
            if not visited[v]:
                heapq.heappush(heap, (weight, v))
                
    print(total_weight)

if __name__ == "__main__":
    solve()

