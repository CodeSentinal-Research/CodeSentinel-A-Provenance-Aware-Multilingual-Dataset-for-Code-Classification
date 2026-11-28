# problem title : Minimum Cost to Connect All Cities
# Solve the stated task using standard input and standard output.
from typing import List

def min_cost_connect_cities(n: int, connections: List[List[int]]) -> int:
    parent = list(range(n + 1))
    def find(i):
        if parent[i] == i: return i
        parent[i] = find(parent[i])
        return parent[i]

    connections.sort(key=lambda c: c[2])
    total_cost = 0
    count = 0

    for u, v, cost in connections:
        ru, rv = find(u), find(v)
        if ru != rv:
            parent[ru] = rv
            total_cost += cost
            count += 1
            if count == n - 1:
                return total_cost
    return -1 if count < n - 1 else total_cost

if __name__ == '__main__':
    n, m = map(int, input().split())
    conns = [list(map(int, input().split())) for _ in range(m)]
    print(min_cost_connect_cities(n, conns))
