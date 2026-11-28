def is_hamiltonian(graph, v, path, pos):
    if pos == v:
        return graph[path[pos - 1], path[pos % v]]
    return graph[path[pos - 1], path[pos]] + graph[path[pos], path[pos + 1 % v]]

def tsp(graph, v, path, pos):
    if pos == v:
        if graph[path[pos - 1], path[pos % v]] != 0:
            return False
        return True

    for i in range(v):
        if graph[path[pos - 1], path[i]] != 0:
            path[pos] = path[i]
            if tsp(graph, v, path, pos + 1) == True:
                return True
            path[pos] = -1
    return False

def main():
    n, m = map(int, input().split())
    graph = [[0 for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1

    path = [-1] * n
    path[0] = 0
    if tsp(graph, n, path, 1) == False:
        print("NO")
    else:
        print("YES")

if __name__ == "__main__":
    main()