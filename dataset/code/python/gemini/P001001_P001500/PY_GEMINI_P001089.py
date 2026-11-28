from typing import List
from collections import deque

def find_tree_centers(n: int, edges: List[List[int]]) -> List[int]:
    if n == 1:
        return [0]
    adj = [set() for _ in range(n)]
    for u, v in edges:
        adj[u].add(v)
        adj[v].add(u)

    leaves = deque([i for i in range(n) if len(adj[i]) == 1])
    remaining = n
    while remaining > 2:
        num_leaves = len(leaves)
        remaining -= num_leaves
        for _ in range(num_leaves):
            leaf = leaves.popleft()
            neighbor = adj[leaf].pop()
            adj[neighbor].remove(leaf)
            if len(adj[neighbor]) == 1:
                leaves.append(neighbor)
    return sorted(list(leaves))

if __name__ == '__main__':
    n = int(input())
    edges = [list(map(int, input().split())) for _ in range(n - 1)]
    print(" ".join(map(str, find_tree_centers(n, edges))))