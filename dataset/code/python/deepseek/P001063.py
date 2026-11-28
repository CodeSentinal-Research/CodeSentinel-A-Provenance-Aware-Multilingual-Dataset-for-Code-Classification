Here is the Python code for the problem:

def count_vertices_with_zero_out_degree():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    in_degree = [0 for _ in range(N)]

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)
        in_degree[v-1] += 1

    count = sum(1 for degree in in_degree if degree == 0)
    print(count)

count_vertices_with_zero_out_degree()

In this code, we first read the number of vertices and edges from the input. We then create an empty list `graph` to represent the graph and a list `in_degree` to represent the in-degree of each vertex. We read the edges and update the graph and in_degree lists accordingly. Finally, we count the number of vertices with in-degree 0 and print it.