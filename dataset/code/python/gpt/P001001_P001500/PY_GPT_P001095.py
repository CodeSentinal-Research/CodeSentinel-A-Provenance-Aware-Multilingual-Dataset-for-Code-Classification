# problem title : Maximum Flow
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def max_flow(n: int, capacity: List[List[int]], src: int, sink: int) -> int:
    flow = 0
    while True:
        parent = [-1] * n
        parent[src] = -2
        q = deque([(src, float('inf'))])
        aug = 0
        while q:
            u, cur_cap = q.popleft()
            if u == sink:
                aug = cur_cap
                break
            for v in range(n):
                if parent[v] == -1 and capacity[u][v] > 0:
                    parent[v] = u
                    q.append((v, min(cur_cap, capacity[u][v])))
        if aug == 0:
            break
        flow += aug
        curr = sink
        while curr != src:
            p = parent[curr]
            capacity[p][curr] -= aug
            capacity[curr][p] += aug
            curr = p
    return flow

if __name__ == '__main__':
    n, m = map(int, input().split())
    cap = [[0] * n for _ in range(n)]
    for _ in range(m):
        u, v, c = map(int, input().split())
        cap[u][v] += c
    src, sink = map(int, input().split())
    print(max_flow(n, cap, src, sink))
