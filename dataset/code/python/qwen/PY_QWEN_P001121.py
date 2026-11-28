import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    degree = [0] * (n + 1)
    
    for _ in range(n - 1):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        degree[u] += 1
        degree[v] += 1
        
    leaves = deque([i for i in range(1, n + 1) if degree[i] <= 1])
    remaining = n
    
    while remaining > 2:
        leaf_count = len(leaves)
        remaining -= leaf_count
        for _ in range(leaf_count):
            u = leaves.popleft()
            for v in adj[u]:
                degree[v] -= 1
                if degree[v] == 1:
                    leaves.append(v)
                    
    print(*sorted(leaves))

if __name__ == "__main__":
    solve()

