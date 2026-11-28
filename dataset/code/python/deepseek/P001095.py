Here is the Python code for the Maximum Flow problem:

def max_flow(graph, source, sink):

    def dfs(vertex, limit):
        if vertex == sink:
            return limit

        for i, capacity in enumerate(graph[vertex]):
            if capacity > 0 and dfs(i, min(limit, capacity)) > 0:
                graph[vertex][i] -= dfs(vertex, limit)
                graph[i][vertex] += dfs(vertex, limit)
                return dfs(sink, limit)

    total_flow = 0
    while dfs(source, float("inf")) > 0:
        total_flow += dfs(source, float("inf"))

    return total_flow


def main():
    N, M, S, T = map(int, input().split())
    graph = [[0 for _ in range(N)] for _ in range(N)]

    for _ in range(M):
        u, v, capacity = map(int, input().split())
        graph[u][v] = capacity

    print(max_flow(graph, S, T))


if __name__ == "__main__":
    main()

This code first reads the number of nodes (N), edges (M), source (S), and sink (T) from the input. Then it reads the capacities of the edges and adds them to the graph. Finally, it prints the maximum flow from the source to the sink.

Please note that this code uses the Edmonds-Karp algorithm for finding the maximum flow in a flow network. The Edmonds-Karp algorithm is a dynamic programming algorithm that finds the maximum flow in a flow network in O(VE^2) time. It uses a modified version of the Ford-Fulkerson algorithm, which is a more efficient version of Edmonds-Karp.