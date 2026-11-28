import sys
import heapq

def dijkstra(graph, source, destination, k):
    distances = {node: float('infinity') for node in graph}
    distances[source] = 0
    previous_nodes = {node: None for node in graph}
    heap = [(0, source)]

    while heap:
        (dist, current_node) = heapq.heappop(heap)

        if dist != distances[current_node]:
            continue

        for neighbor, neighbor_distance in graph[current_node].items():
            distance = dist + neighbor_distance

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous_nodes[neighbor] = current_node
                heapq.heappush(heap, (distance, neighbor))

        if current_node == destination:
            return distances[destination]

    return float('infinity')

def solve():
    N, M, S, D, K = map(int, sys.stdin.readline().split())
    graph = {i: {} for i in range(1, N+1)}

    for _ in range(M):
        u, v, cost = map(int, sys.stdin.readline().split())
        graph[u][v] = cost

    result = dijkstra(graph, S, D, K)
    print(result if result != float('infinity') else -1)

if __name__ == "__main__":
    solve()