import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    rev_adj = [[] for _ in range(n + 1)]
    in_degree = [0] * (n + 1)
    
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        rev_adj[v].append(u)
        in_degree[v] += 1
        
    # Find nodes not part of any cycle (Safe states)
    # Nodes with out-degree 0 are safe.
    # Reverse graph: Nodes with in-degree 0 in original are sources.
    # Actually, safe nodes are those that do not lead to a cycle.
    # Topological sort on reversed graph? No.
    # Standard approach: Identify nodes in cycles using DFS or Kahn's on reversed graph?
    # Kahn's algorithm removes nodes with in-degree 0. In reverse graph, this removes nodes with out-degree 0 in original.
    # If we remove all nodes that eventually lead to a sink (out-degree 0) in the original graph?
    # Correct definition: A node is safe if all paths from it lead to a terminal node (out-degree 0).
    # This is equivalent to finding nodes not in any cycle and not reaching any cycle.
    # We can use reverse topological sort. Start with nodes having out-degree 0.
    
    out_degree = [len(adj[i]) for i in range(n + 1)]
    q = deque([i for i in range(1, n + 1) if out_degree[i] == 0])
    safe = set(q)
    
    while q:
        u = q.popleft()
        for v in rev_adj[u]: # v has an edge to u in original graph
            out_degree[v] -= 1
            if out_degree[v] == 0:
                safe.add(v)
                q.append(v)
                
    print(*sorted(safe))

if __name__ == "__main__":
    solve()

