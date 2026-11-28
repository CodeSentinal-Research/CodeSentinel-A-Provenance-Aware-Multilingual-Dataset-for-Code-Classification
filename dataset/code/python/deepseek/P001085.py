def main():
    N, M, S, T = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
    paths = [0] * (N + 1)
    paths[S] = 1
    for u in range(1, N + 1):
        for v in graph[u]:
            paths[u] += paths[v]
    print(paths[T])

if __name__ == '__main__':
    main()