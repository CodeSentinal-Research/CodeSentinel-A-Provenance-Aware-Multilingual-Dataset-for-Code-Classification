import sys
import heapq

def solve():
    N, M, S = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N+1)]
    distances = [sys.maxsize] * (N+1)
    distances[S] = 0
    for _ in range(M):
        u, v, w = map(int, sys.stdin.readline().split())
        graph[u].append((v, w))
    queue = [(0, S)]
    while queue:
        dist, node = heapq.heappop(queue)
        if dist < distances[node]:
            continue
        for neighbor, weight in graph[node]:
            if distances[neighbor] > dist + weight:
                distances[neighbor] = dist + weight
                heapq.heappush(queue, (distances[neighbor], neighbor))
    for i in range(1, N+1):
        print(distances[i] if distances[i] != sys.maxsize else -1)

if __name__ == '__main__':
    solve()

This Python code uses the Dijkstra's algorithm for shortest path in a Directed Acyclic Graph. The graph is represented as an adjacency list. The input is taken from standard input. The `solve` function first initializes the graph, distances array and the queue. Then, it reads the number of edges and vertices, and populates the graph and the distances array. Afterwards, it populates the queue with the source vertex and starts the Dijkstra's algorithm. It continues populating the queue until it is empty, and finally, it prints the shortest distances from the source vertex to all other vertices.