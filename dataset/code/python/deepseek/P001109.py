def is_valid(graph, colors):
    def dfs(v, c):
        colors[v] = c
        for u in graph[v]:
            if colors[u] == c:
                return False
            if colors[u] == 0 and not dfs(u, -c):
                return False
        return True

    for v in range(len(graph)):
        if colors[v] == 0 and not dfs(v, 1):
            return False
    return True

def main():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u - 1].append(v - 1)
        graph[v - 1].append(u - 1)
    colors = [0] * N
    for v in range(N):
        if colors[v] == 0 and not dfs(v, 1):
            print("INVALID")
            return
    print("VALID")

if __name__ == "__main__":
    main()