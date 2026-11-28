import sys
import heapq

def shortest_distance(N, M, K, edges, sources):
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v, w = map(int, sys.stdin.readline().split())
        graph[u-1].append((v-1, w))

    distances = [float('inf')] * N
    distances[sources[0]-1] = 0

    pq = [(0, sources[0])]
    while pq:
        cur_dist, cur_vertex = heapq.heappop(pq)

        if cur_dist > distances[cur_vertex]:
            continue

        for neighbor, dist in graph[cur_vertex]:
            distance = cur_dist + dist
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    for distance in distances:
        print(distance if distance != float('inf') else 'INF')

if __name__ == "__main__":
    N, M, K = map(int, sys.stdin.readline().split())
    sources = list(map(int, sys.stdin.readline().split()))

    edges = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

    shortest_distance(N, M, K, edges, sources)

This code first reads the number of nodes, edges, and sources from the input. It then constructs a graph from the edges. It also sets all the distances to infinity. The sources are processed from left to right. For each source, all its neighboring nodes are calculated and their distance is updated if it's smaller than the current distance. The distance is updated by the edge's weight. After processing all sources, the shortest distance to all nodes is printed.