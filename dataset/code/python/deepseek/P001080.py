Here is the Python code for the problem:

from collections import defaultdict

def find_articulation_points(n, edges):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    articulation_points = []
    visited = [0] * (n + 1)
    low = [0] * (n + 1)
    disc = [0] * (n + 1)
    ap = [False] * (n + 1)

    def dfs(u, p=None):
        visited[u] = 1
        children = 0
        bridge = 0
        for v in graph[u]:
            if visited[v] == 0:
                children += 1
                dfs(v, u)
                if low[v] > disc[u]:
                    bridge += 1
                low[u] = min(low[u], low[v])
            elif v != p:
                low[u] = min(low[u], disc[v])
        if (p is not None and low[u] > disc[p]) or (children > 1 and bridge == 0):
            ap[u] = True

    for u in range(1, n + 1):
        if visited[u] == 0:
            dfs(u)

    for u in range(1, n + 1):
        if ap[u]:
            articulation_points.append(u)

    if len(articulation_points) == 0:
        print("NONE")
    else:
        articulation_points.sort()
        print(' '.join(map(str, articulation_points)))


if __name__ == "__main__":
    n, m = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(m)]
    find_articulation_points(n, edges)

This code first reads the number of vertices (n) and edges (m), then it reads the edges and stores them in a list of tuples. It then calls the `find_articulation_points` function with the number of vertices and edges. The `find_articulation_points` function creates a graph from the edges, then it uses a Depth-First Search (DFS) algorithm to find articulation points. It keeps track of visited nodes, low links, and discovery times, and marks articulation points as well. Finally, it prints the articulation points in ascending order.