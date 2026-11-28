Here is the Python code for the problem:

def is_hamiltonian(edges, n):
    graph = [[] for _ in range(n)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    
    visited = [False] * n
    path = [None] * n

    if dfs(graph, visited, path, 0, n):
        return 'YES'
    else:
        return 'NO'

def dfs(graph, visited, path, start, n):
    visited[start] = True
    path[start] = 0

    if n == 1 and start == 0:
        return True

    for v in graph[start]:
        if visited[v] == False:
            if dfs(graph, visited, path, v, n - 1) == True:
                return True

    visited[start] = False
    return False

def main():
    n, m = map(int, input().split())
    edges = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]
    print(is_hamiltonian(edges, n))

if __name__ == "__main__":
    main()

This Python program takes the graph edges as input and uses a depth-first search to check if the graph contains a Hamiltonian cycle. The `is_hamiltonian` function creates a graph from the edges, and then calls the `dfs` function to check if the graph contains a Hamiltonian cycle. The `dfs` function marks each node as visited and the path length, and then recursively checks if the graph contains a Hamiltonian cycle starting from the first node.