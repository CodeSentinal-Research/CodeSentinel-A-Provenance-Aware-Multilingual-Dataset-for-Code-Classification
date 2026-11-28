def floyd_warshall(N, M, edges):
    dist = [[float('inf')] * N for _ in range(N)]

    for i in range(N):
        dist[i][i] = 0

    for edge in edges:
        u, v, w = edge
        dist[u][v] = w

    for k in range(N):
        for i in range(N):
            for j in range(N):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for i in range(N):
        for j in range(N):
            if dist[i][j] == float('inf'):
                dist[i][j] = 'INF'
            else:
                dist[i][j] = dist[i][j]

    return dist


def main():
    N, M = map(int, input().split())
    edges = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]

    dist = floyd_warshall(N, M, edges)

    for row in dist:
        print(' '.join(map(str, row)))


if __name__ == "__main__":
    main()