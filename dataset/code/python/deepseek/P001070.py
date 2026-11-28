Here is the Python code for the problem:

def check_bipartite():
    N, M = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(M)]

    graph = [[] for _ in range(N + 1)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    color = [0] * (N + 1)
    color[1] = 1

    queue = [1]
    while queue:
        node = queue.pop(0)
        for neighbour in graph[node]:
            if color[neighbour] == 0:
                color[neighbour] = -color[node]
                queue.append(neighbour)
            elif color[neighbour] == color[node]:
                return "NO"

    return "YES"

if __name__ == "__main__":
    print(check_bipartite())

This code reads the number of nodes and edges, and then the edges themselves. The graph is then represented as an adjacency list. The bipartite graph is colored with two colors: 1 and -1. We start from node 1 and color it with +1. Then we color all the neighbours of the current node with -1. If a neighbour is already colored, then we know that the graph is not bipartite, so we return "NO". If no uncolored neighbour is found, we return "YES".