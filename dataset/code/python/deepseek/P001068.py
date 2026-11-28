Here is the Python code for the problem:

from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def topologicalSortUtil(self, v, visited, stack):
        visited[v] = True

        for i in self.graph[v]:
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)

        stack.insert(0, v)

    def topologicalSort(self):
        visited = [False] * (self.V + 1)
        stack = []

        for i in range(self.V):
            if visited[i] == False:
                self.topologicalSortUtil(i, visited, stack)

        return stack

def main():
    [N, M] = list(map(int, input().split()))
    g = Graph(N)
    for i in range(M):
        [u, v] = list(map(int, input().split()))
        g.addEdge(u, v)

    result = g.topologicalSort()
    if result:
        print(' '.join(map(str, result)))
    else:
        print('IMPOSSIBLE')

if __name__ == "__main__":
    main()

This program creates a graph and performs a topological sort on it. The topological sort is performed by using a Depth-First Search approach. It maintains a list of all vertices which are still not processed. It starts from the vertex with no incoming edges and moves to vertices which have no incoming edges.

In the main function, we first get the number of vertices (N) and edges (M) from the input. Then, we create a graph and add edges based on the input. Finally, we perform the topological sort and print the result.