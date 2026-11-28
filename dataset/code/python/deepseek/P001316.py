def main():
    V, E, M = map(int, input().split())
    graph = [list() for _ in range(V)]
    colors = [0] * V

    for _ in range(E):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)

    for node in range(V):
        graph[node].sort(key=lambda x, u=node: colors[x] > colors[u])

    stack = list(range(V))
    color = 1

    for node in stack:
        if colors[node] == 0:
            colors[node] = color
            stack.remove(node)

            for adjacent in graph[node]:
                if colors[adjacent] == 0:
                    stack.append(adjacent)

            color += 1
            if color > M:
                return 'NO'

    return 'YES'

if __name__ == '__main__':
    print(main())
This code reads a graph and M colors from input, then computes a topological sort on the graph. If the topological sort is possible, it means that there is no cycle that can lead to a cycle in the graph, which can be colored with M colors. If the topological sort is not possible, then it means that there is a cycle in the graph which can't be colored with M colors.