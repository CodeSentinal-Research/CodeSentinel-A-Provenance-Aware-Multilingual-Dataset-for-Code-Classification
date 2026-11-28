import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        k = int(input_data[idx]); idx += 1
        for _ in range(k):
            v = int(input_data[idx]); idx += 1
            adj[i].append(v)
            
    # Clone directed graph
    clones = [None] * (n + 1)
    clones[1] = {'val': 1, 'neighbors': []}
    q = deque([1])
    visited = set([1])
    
    while q:
        u = q.popleft()
        for v in adj[u]:
            if v not in visited:
                visited.add(v)
                clones[v] = {'val': v, 'neighbors': []}
                q.append(v)
            clones[u]['neighbors'].append(v)
            
    for i in range(1, n + 1):
        neighbors = sorted(clones[i]['neighbors'])
        print(f"{i}: {' '.join(map(str, neighbors))}")

if __name__ == "__main__":
    solve()

