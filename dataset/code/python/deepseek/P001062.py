def count_vertices_with_zero_indegree(N, M, edges):
    in_degree = [0] * (N+1)

    for edge in edges:
        u, v = edge
        in_degree[v] += 1

    return in_degree.count(0)

def main():
    N, M = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(M)]

    print(count_vertices_with_zero_indegree(N, M, edges))

if __name__ == "__main__":
    main()