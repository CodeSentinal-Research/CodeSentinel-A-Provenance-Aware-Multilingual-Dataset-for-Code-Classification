def bellman_ford(num_vertices, edges, source):
    distances = [float('inf')] * num_vertices
    distances[source] = 0

    for _ in range(num_vertices - 1):
        for edge in edges:
            u, v, w = edge
            if distances[u] + w < distances[v]:
                distances[v] = distances[u] + w

    for edge in edges:
        u, v, w = edge
        if distances[u] + w < distances[v]:
            print('NEGATIVE CYCLE')
            return

    print(' '.join(map(str, distances)))


def main():
    num_vertices, num_edges, source = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(num_edges)]
    bellman_ford(num_vertices, edges, source)


if __name__ == "__main__":
    main()