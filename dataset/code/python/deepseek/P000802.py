def max_side_length(N, M, grid, threshold):
    prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
    for i in range(N):
        for j in range(M):
            prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j] + grid[i][j]

    max_length = 0
    max_sum = 0

    for i in range(N, 0, -1):
        for j in range(M, 0, -1):
            for k in range(min(i, N - i + 1), 0, -1):
                for l in range(min(j, M - j + 1), 0, -1):
                    curr_sum = prefix_sum[i][j] - prefix_sum[i - k][j] - prefix_sum[i][j - l] + prefix_sum[i - k][j - l]
                    if curr_sum <= threshold:
                        if k > max_length:
                            max_length = k
                            max_sum = curr_sum
                        break

    return max_length

def main():
    N = int(input())
    M = int(input())
    grid = [[int(i) for i in input().split()] for _ in range(N)]
    threshold = int(input())
    print(max_side_length(N, M, grid, threshold))

if __name__ == "__main__":
    main()