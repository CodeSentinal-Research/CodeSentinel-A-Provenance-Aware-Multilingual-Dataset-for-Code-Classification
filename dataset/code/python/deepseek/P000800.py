Here is the Python code for the problem:

def solve(N, M, grid, Q, queries):
    prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j] + grid[i][j]

    for query in queries:
        r1, c1, r2, c2 = query
        rectangle_sum = prefix_sum[r2 + 1][c1 + 1] - prefix_sum[r1][c1 + 1] - prefix_sum[r2 + 1][c1] + prefix_sum[r1][c2 + 1]
        print(rectangle_sum)

if __name__ == "__main__":
    N = 5
    M = 5
    grid = [[1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [1, 2, 3, 4, 5]]
    Q = 2
    queries = [[1, 1, 2, 2], [2, 3, 3, 4]]
    solve(N, M, grid, Q, queries)

This code first preprocesses the matrix using a 2D prefix sum. For each query, it calculates the sum of the elements inside the rectangle defined by the top-left corner and bottom-right corner of the query rectangle. The preprocessed matrix and the queries are passed to the `solve` function, which prints the sums of the rectangle queries.