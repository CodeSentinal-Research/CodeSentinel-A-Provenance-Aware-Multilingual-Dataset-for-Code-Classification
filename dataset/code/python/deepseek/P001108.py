Here is the Python code for the problem:

def solve(N, M, Q, edges, queries):
    graph = [[] for _ in range(N+1)]
    reachable = [0 for _ in range(N+1)]

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)

    for _ in range(Q):
        u, v = map(int, input().split())
        reachable[v] = 1
        stack = [u]
        while stack:
            node = stack.pop()
            for neighbor in graph[node]:
                if not reachable[neighbor]:
                    stack.append(neighbor)
                    reachable[neighbor] = 1

    for u, v in queries:
        print("YES" if reachable[v] else "NO")


def main():
    N, M, Q = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(M)]
    queries = [list(map(int, input().split())) for _ in range(Q)]
    solve(N, M, Q, edges, queries)


if __name__ == "__main__":
    main()

The code first reads the number of nodes, edges, and queries. Then it reads the edges and queries for the graph and the queries separately. After that, it calls the `solve` function with the parameters.

The `solve` function creates a graph and a list of reachable nodes, then it reads the edges. For each edge, it adds the end node to the reachable list. Then it performs a depth-first search from each node in the reachable list to all other nodes. If a node can be reached from the current node, it adds the other node to the reachable list of the current node.

Finally, it prints the reachability of each query node.