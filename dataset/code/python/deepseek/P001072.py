Sure, here is the Python code with the main function and input handling.

def main():
    N, M = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(M)]
    graph = [[] for _ in range(N+1)]
    for u, v in edges:
        graph[u].append(v)
    visited = [0] * (N+1)
    count = 0

    def dfs(v, color):
        visited[v] = 1
        for u in graph[v]:
            if not visited[u]:
                dfs(u, color)
            elif visited[u] and color != u:
                return False
        return True

    for v in range(1, N+1):
        if not visited[v]:
            if not dfs(v, v):
                return 0

    count += 1
    visited = [0] * (N+1)
    for v in range(1, N+1):
        if not visited[v]:
            if not dfs(v, v):
                return 0

    return count

print(main())

In this code, we first read the number of nodes and edges. Then, we read the edges and build the graph. The main function then uses a depth-first search (DFS) to find the number of strongly connected components.