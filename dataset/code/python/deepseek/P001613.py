def matrix_block_sum(N, M, K):
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().split())))

    prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i - 1][j - 1]

    for i in range(N):
        for j in range(M):
            top = max(0, i - K)
            left = max(0, j - K)
            bottom = min(N, i + K + 1)
            right = min(M, j + K + 1)
            print(prefix_sum[bottom][right] - prefix_sum[top][right] - prefix_sum[bottom][left] + prefix_sum[top][left])

if __name__ == "__main__":
    N, M, K = map(int, input().split())
    matrix_block_sum(N, M, K)