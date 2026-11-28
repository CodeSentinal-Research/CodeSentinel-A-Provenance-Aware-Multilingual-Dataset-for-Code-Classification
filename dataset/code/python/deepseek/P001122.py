def input_data():
    N, M = map(int, input().split())
    edges = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
    return N, edges

def find_safe_vertices(N, edges):
    graph = [[] for _ in range(N)]
    safe_vertices = [[] for _ in range(N)]

    for u, v in edges:
        graph[v].append(u)

    visited = [False] * N

    def dfs(v):
        visited[v] = True
        for u in graph[v]:
            if visited[u] == False:
                dfs(u)

    for v in range(N):
        if visited[v] == False:
            dfs(v)
            safe_vertices[v] = [i for i in range(N) if visited[i]]
            visited[v] = False

    for v in range(N):
        print(*sorted(safe_vertices[v]))

def main():
    N, edges = input_data()
    find_safe_vertices(N, edges)

if __name__ == "__main__":
    main()