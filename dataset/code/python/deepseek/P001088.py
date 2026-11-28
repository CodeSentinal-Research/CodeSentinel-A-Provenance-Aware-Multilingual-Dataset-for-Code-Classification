def count_vertices_at_distance_k(N, M, S, K):
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)

    visited = [False]*N
    distance = [0]*N
    parent = [None]*N

    def bfs():
        queue = [S]
        visited[S] = True
        while queue:
            u = queue.pop(0)
            for v in graph[u]:
                if not visited[v]:
                    queue.append(v)
                    visited[v] = True
                    distance[v] = distance[u] + 1
                    parent[v] = u
                elif distance[u] - distance[v] >= 0 and distance[u] - distance[v] <= K:
                    count[0] += 1

    count = [0]
    bfs()
    print(count[0])

N, M, S, K = map(int, input().split())
count_vertices_at_distance_k(N, M, S-1, K)

In this code, we create an adjacency list of the graph, then use a Breadth-First Search (BFS) to find all vertices at distance K.

We use a queue and a visited array to track the vertices we've visited. The distance array keeps track of the distance of each vertex from the source, and the parent array is used to reconstruct the path from the source to each vertex. 

In the BFS, for each vertex u in the queue, we visit all its neighbors v, and if v has not been visited yet, we mark it as visited and add it to the queue and the distance array. If v is at distance K from u, we increment the count of vertices at distance K. 

Finally, we print the count of vertices at distance K.