Here is the Python code for the problem:

from collections import deque

def findMinHeightTrees(N, edges):
    if N <= 2:
        return [i for i in range(N)]

    graph = [[] for _ in range(N)]
    degrees = [0] * N

    for edge in edges:
        a, b = edge[0], edge[1]
        graph[a].append(b)
        graph[b].append(a)
        degrees[a] += 1
        degrees[b] += 1

    level = deque([i for i in range(N) if degrees[i] == 1])
    reached = set()

    while level:
        next_level = deque()
        for node in level:
            reached.add(node)
            for neighbor in graph[node]:
                degrees[neighbor] -= 1
                if degrees[neighbor] == 1:
                    next_level.append(neighbor)
        level = next_level

    return reached


def main():
    N = int(input().strip())
    edges = []
    for i in range(N - 1):
        edges.append(list(map(int, input().strip().split())))
    result = findMinHeightTrees(N, edges)
    print(result)


if __name__ == "__main__":
    main()

This code firstly reads the number of nodes N and then reads the edges. It then finds all the root vertices of the minimum height trees. The function `findMinHeightTrees` is a breadth-first search (BFS) algorithm that finds all the root vertices of the minimum height trees. It uses a queue (deque) to store the nodes that need to be processed, and a set (reached) to store the nodes that have been processed. The nodes are processed by their degree. When a node's degree becomes 1, it is added to the next level. The process continues until all nodes have been processed.