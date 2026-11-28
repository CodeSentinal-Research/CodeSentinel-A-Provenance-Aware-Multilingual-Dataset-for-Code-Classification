Here is the python code:

import sys
import heapq

def min_delay_time(N, M, S, graph, weights):
    delay = [sys.maxsize] * (N + 1)
    delay[S] = 0
    heap = [(0, S)]

    while heap:
        current_delay, current_node = heapq.heappop(heap)

        for neighbour, weight in graph[current_node]:
            new_delay = current_delay + weight
            if new_delay < delay[neighbour]:
                delay[neighbour] = new_delay
                heapq.heappush(heap, (new_delay, neighbour))

    for i in range(1, N + 1):
        if delay[i] == sys.maxsize:
            print(-1)
        else:
            print(delay[i])

def main():
    N, M, S = map(int, input().split())
    graph = [[] for _ in range(N + 1)]
    weights = [[] for _ in range(N + 1)]

    for _ in range(M):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        weights[u].append(w)

    min_delay_time(N, M, S, graph, weights)

if __name__ == "__main__":
    main()

In this code, we use a priority queue to keep track of the nodes with the minimum delay time. We start by initializing the delay time for all nodes to be infinite, except for the starting node. We then start a loop that continues until there are no more nodes with a delay time less than the current one. For each node, we add its neighbours to the priority queue. If the new delay time is less than the current delay time for the neighbour, we update the delay time for the neighbour.

The time complexity for this algorithm is O(M log M) because we need to visit each edge M times. The space complexity is O(N + M) because we need to store the graph and the delay times.