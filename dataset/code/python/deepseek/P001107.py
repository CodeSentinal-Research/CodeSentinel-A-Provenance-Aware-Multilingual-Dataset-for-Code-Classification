def transitive_closure(edges, n):
    matrix = [[0 for _ in range(n)] for _ in range(n)]
    for (src, dest) in edges:
        matrix[src][dest] = 1
    for k in range(n):
        for i in range(n):
            for j in range(n):
                matrix[i][j] = max(matrix[i][j], matrix[i][k] and matrix[k][j])
    return matrix

def main():
    n, m = map(int, input().split())
    edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]
    matrix = transitive_closure(edges, n)
    for row in matrix:
        print(*row)

if __name__ == "__main__":
    main()

In this code, we start by reading the number of vertices (N) and the number of edges (M). Then, for each edge, we update the matrix based on the transitive closure property. The transitive closure property is that for any vertex i, if vertex j is reachable from i, then it is also reachable from any other vertex.

Finally, we print out the reachability matrix.