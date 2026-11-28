def find_neighbors(N, M, edges, V):
    graph = {}
    for _ in range(M):
        u, v = map(int, input().split())
        if u not in graph:
            graph[u] = [v]
        else:
            graph[u].append(v)
        if v not in graph:
            graph[v] = [u]
        else:
            graph[v].append(u)
    neighbors = sorted(graph[V])
    print(*neighbors)

N, M = map(int, input().split())
edges = []
for _ in range(M):
    u, v = map(int, input().split())
    edges.append((u, v))
V = int(input())
find_neighbors(N, M, edges, V)
This Python code first reads the input for the graph and then calls the `find_neighbors` function with the required parameters. The `find_neighbors` function constructs the graph using an adjacency list representation and then sorts and prints the neighbors of the given vertex.