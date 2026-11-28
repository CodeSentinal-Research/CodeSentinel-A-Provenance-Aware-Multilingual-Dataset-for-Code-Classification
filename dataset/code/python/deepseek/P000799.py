def construct_prefix_sum_matrix(N, M, matrix):
    prefix_sum_matrix = [[0 for _ in range(M + 1)] for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            prefix_sum_matrix[i][j] = prefix_sum_matrix[i - 1][j] + prefix_sum_matrix[i][j - 1] - prefix_sum_matrix[i - 1][j - 1] + matrix[i - 1][j - 1]

    return prefix_sum_matrix


def main():
    N = int(input().strip())
    M = int(input().strip())

    matrix = []
    for _ in range(N):
        row = [int(x) for x in input().strip().split()]
        matrix.append(row)

    prefix_sum_matrix = construct_prefix_sum_matrix(N, M, matrix)

    for row in prefix_sum_matrix:
        print(' '.join(str(x) for x in row))


if __name__ == "__main__":
    main()