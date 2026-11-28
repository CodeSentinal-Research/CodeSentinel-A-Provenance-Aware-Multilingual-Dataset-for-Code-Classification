Here is a Python solution for the problem using Depth-First Search (DFS) for finding connected components in an undirected graph.

def dfs(graph, visited, v):
    visited[v] = True
    for i in range(len(graph)):
        if graph[v][i] == 1 and not visited[i]:
            dfs(graph, visited, i)

def solve():
    N = int(input().strip())
    graph = []
    for _ in range(N):
        row = list(map(int, input().strip().split()))
        graph.append(row)

    visited = [False] * N
    provinces = 0
    for v in range(N):
        if not visited[v] and graph[v][v] == 1:
            dfs(graph, visited, v)
            provinces += 1

    print(provinces)

if __name__ == "__main__":
    solve()

In this code, we first read the number of cities (N) and the adjacency matrix from the input. Then, we use Depth-First Search to find all connected components. For each city (v), if it has not been visited and is connected to another city via an edge, we perform a DFS from this city and increase the count of provinces. Finally, we print the number of provinces.