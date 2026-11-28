Sure, here is a Python solution for the problem. This solution uses graph theory and the concept of a Eulerian Path. A Eulerian Path in a graph is a path that visits each vertex exactly once, and in the end, you will be on your starting vertex. This solution assumes that you are given a list of edges in the form of numbers (representing edges in graph), where each number is a edge of the graph.

def find_eulerian_circuit(edges, N):
    adj = [[] for _ in range(N)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)

    visited = [False] * N
    for i in range(N):
        if len(adj[i]) > 0 and visited[i] == False:
            cycle = []
            stack = [i]
            while len(stack) > 0:
                curr = stack[-1]
                visited[curr] = True
                stack.pop()
                cycle.append(curr)
                for neighbor in adj[curr]:
                    if visited[neighbor] == False:
                        stack.append(neighbor)
            if len(cycle) > 2:
                return "IMPOSSIBLE"
            if len(cycle) == 2:
                return [cycle[0], cycle[1], cycle[2]]

    for i in range(N):
        if len(adj[i]) > 0:
            return "IMPOSSIBLE"

    return "IMPOSSIBLE"


def main():
    N, M = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(M)]
    print(find_eulerian_circuit(edges, N))


if __name__ == "__main__":
    main()

This code firstly creates an adjacency list from the given edges. Then it tries to find all cycles in the graph, i.e., all cycles of size 2 or 3 (since we need a Hamiltonian Path). It finds a cycle and returns the elements of the cycle if it exists, otherwise it returns IMPOSSIBLE.