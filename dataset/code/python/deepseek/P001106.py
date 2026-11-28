def topo_sort(graph):
    visited = [False] * (len(graph) + 1)
    result = []

    def visit(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                visit(neighbor)
        result.append(node)

    for node in range(1, len(graph)):
        if not visited[node]:
            visit(node)

    return result[::-1]  

def main():
    N, M = map(int, input().split())
    graph = [[] for _ in range(N + 1)]

    for _ in range(M):
        prerequisite_forks = list(map(int, input().split()))
        for prerequisite in prerequisite_forks[1:]:
            graph[prerequisite].append(prerequisite_forks[0])

    result = topo_sort(graph)

    if len(result) != N:
        print('IMPOSSIBLE')
    else:
        for course in result:
            print(course)

if __name__ == '__main__':
    main()