def count_reachable_vertices():
    N, M, S = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    reachable = [False] * N
    reachable[S-1] = True
    queue = [S-1]
    while queue:
        vertex = queue.pop(0)
        for neighbor in graph[vertex]:
            if not reachable[neighbor]:
                reachable[neighbor] = True
                queue.append(neighbor)
    print(sum(reachable))

count_reachable_vertices()