def check_edge():
    N, M, Q = map(int, input().split())

    graph = [[] for _ in range(N+1)]

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    for _ in range(Q):
        u, v = map(int, input().split())
        if v in graph[u]:
            print('YES')
        else:
            print('NO')

check_edge()