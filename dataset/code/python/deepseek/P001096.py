Here is the Python code for the problem:

import sys
from queue import PriorityQueue

def minimum_cut_problem():
    N, M, S, T = map(int, sys.stdin.readline().split())

    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v, capacity = map(int, sys.stdin.readline().split())
        graph[u].append((v, capacity))
        graph[v].append((u, capacity))

    parent = [0] * (N + 1)
    distance = [sys.maxsize] * (N + 1)
    distance[S] = 0

    pq = PriorityQueue()
    pq.put((0, S))

    while not pq.empty():
        dist, node = pq.get()
        if distance[node] < dist:
            continue
        for neighbor, capacity in graph[node]:
            new_dist = dist + capacity
            if new_dist < distance[neighbor]:
                distance[neighbor] = new_dist
                parent[neighbor] = node
                pq.put((new_dist, neighbor))

    cut_capacity = sys.maxsize
    for node in range(1, N + 1):
        if distance[node] > distance[T]:
            cut_capacity = min(cut_capacity, distance[node])

    print(cut_capacity)

if __name__ == "__main__":
    minimum_cut_problem()

In this code, we use a priority queue to find the shortest path from the source to all other nodes. We use the BFS (Breadth-First Search) algorithm to find the shortest path. The priority queue is used to select the next node with the smallest distance.

The time complexity of this algorithm is O(E log V), where E is the number of edges and V is the number of vertices in the graph. The space complexity is O(V) for storing the distance array and the parent array.