import sys
import heapq

def prims(edges, n):
    parent = {None}
    mst = set()
    weight = 0
    pq = [(0, 0, -1)]

    while pq:
        (cost, node, parent_node) = heapq.heappop(pq)

        if node not in mst:
            mst.add(node)
            weight += cost
            if parent_node is not None:
                print(f'Edge {parent_node} - {node}: {cost}')
            for (child, edge_cost) in edges[node]:
                if child not in mst:
                    heapq.heappush(pq, (edge_cost, child, node))

def main():
    lines = sys.stdin.read().splitlines()
    n, m = map(int, lines[0].split())
    edges = [[] for _ in range(n)]
    for i in range(m):
        u, v, w = map(int, lines[i + 1].split())
        edges[u - 1].append((v - 1, w))
        edges[v - 1].append((u - 1, w))
    prims(edges, n)
    print(f'Weight: {weight}')

if __name__ == "__main__":
    main()