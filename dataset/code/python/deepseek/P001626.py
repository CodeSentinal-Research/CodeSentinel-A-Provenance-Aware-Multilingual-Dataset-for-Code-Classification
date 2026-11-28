def solve(N, M, Threshold, matrix):
    prefix_sums = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            prefix_sums[i + 1][j + 1] = prefix_sums[i + 1][j] + prefix_sums[i][j + 1] - prefix_sums[i][j] + matrix[i][j]

    max_side_length = 0
    for i in range(N, 0, -1):
        for j in range(M, 0, -1):
            side_length = min(i, j, N - i + 1, M - j + 1)
            while side_length > max_side_length:
                if prefix_sums[i][j + side_length] - prefix_sums[i][j] + prefix_sums[i + side_length][j] - prefix_sums[i + side_length][j + side_length] + prefix_sums[i + side_length][j + side_length - 1] - prefix_sums[i + side_length][j + side_length - 1] + prefix_sums[i + side_length - 1][j + side_length] - prefix_sums[i + side_length - 1][j + side_length - 1] + matrix[i - side_length + 1][j - side_length + 1] <= Threshold:
                    max_side_length = side_length
                side_length -= 1

    return max_side_length


def main():
    N, M, Threshold = map(int, input().split())
    matrix = [[int(x) for x in input().split()] for _ in range(N)]
    print(solve(N, M, Threshold, matrix))


if __name__ == "__main__":
    main()