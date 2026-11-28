def findMotherVertex(graph, n):
    visited = [False]*n
    for i in range(n):
        if visited[i] == False:
            if dfs(graph, i, visited):
                return i
    return -1

def dfs(graph, v, visited):
    visited[v] = True
    for neighbor in graph[v]:
        if visited[neighbor] == False:
            dfs(graph, neighbor, visited)
    return True

def main():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
    print(findMotherVertex(graph, N))

main()
This Python code defines a function `findMotherVertex()` that finds the mother vertex in a given directed graph. The mother vertex is a vertex in the graph that, when removed, will make all other vertices reachable from it. The `main()` function reads the input, builds the graph, and then calls the `findMotherVertex()` function to find the mother vertex.