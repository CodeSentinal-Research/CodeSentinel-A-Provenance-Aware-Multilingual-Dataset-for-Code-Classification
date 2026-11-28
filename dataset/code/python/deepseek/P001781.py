def solve(n, edges):
    graph = [[] for _ in range(n + 1)]
    for edge in edges:
        u, v = edge
        graph[u].append(v)
        graph[v].append(u)

    count = 0
    for node in range(1, n + 1):
        count += dfs(node, node, graph)

    return count

def dfs(start, node, graph):
    visited = [False] * (len(graph))
    stack = [node]
    count = 0

    while stack:
        node = stack.pop()
        if visited[node]:
            continue
        visited[node] = True
        count += 1
        stack.extend(graph[node])

    return count == 0

def main():
    n = int(input())
    edges = [list(map(int, input().split()))[1:] for _ in range(n)]
    print(solve(n, edges))

if __name__ == "__main__":
    main()
This program first reads the number of nodes and edges from the input. It then builds the graph using the edges. After that, it traverses each node in the graph and counts the number of symmetric subtrees.