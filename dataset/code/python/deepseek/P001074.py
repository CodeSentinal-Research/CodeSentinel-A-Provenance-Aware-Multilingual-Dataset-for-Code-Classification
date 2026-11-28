import sys
import heapq

def dijkstra(N, M, S, graph):
    shortest_distances = [float('inf')] * (N + 1)
    shortest_distances[S] = 0
    heap = [(0, S)]

    while heap:
        current_distance, current_vertex = heapq.heappop(heap)

        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight

            if distance < shortest_distances[neighbor]:
                shortest_distances[neighbor] = distance
                heapq.heappush(heap, (distance, neighbor))

    for i in range(1, N + 1):
        if shortest_distances[i] == float('inf'):
            print('INF', end=' ')
        else:
            print(shortest_distances[i], end=' ')

def input_data():
    N, M, S = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N + 1)]

    for _ in range(M):
        u, v, w = map(int, sys.stdin.readline().split())
        graph[u].append((v, w))

    return N, M, S, graph

def main():
    N, M, S, graph = input_data()
    dijkstra(N, M, S, graph)

if __name__ == "__main__":
    main()