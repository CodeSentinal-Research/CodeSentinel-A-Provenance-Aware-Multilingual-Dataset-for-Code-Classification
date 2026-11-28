def max_sum_not_exceeding_k(N, M, K, matrix):
    max_sum = max_area = 0

    prefix_sum = [[0 for _ in range(M + 1)] for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + matrix[i - 1][j - 1]

    for i in range(1, N + 1):
        for j in range(i, M + 1):
            for k in range(j, M + 1):
                submatrix_sum = prefix_sum[i][k] - prefix_sum[i - 1][k] - prefix_sum[i][j - 1] + prefix_sum[i - 1][j - 1]
                if submatrix_sum <= K and submatrix_sum > max_sum:
                    max_sum = submatrix_sum
                    max_area = max(max_area, submatrix_sum * (k - j + 1))

    return max_area

def main():
    N, M, K = map(int, input().split())

    matrix = [[int(col) for col in input().split()] for row in range(N)]

    max_area = max_sum_not_exceeding_k(N, M, K, matrix)

    print(max_area)

if __name__ == "__main__":
    main()