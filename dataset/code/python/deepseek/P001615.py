Here is the Python code for the given problem:

def count_submatrices_with_sum_equal_to_target(matrix, target):
    n, m = len(matrix), len(matrix[0])
    prefix_sum = [[0] * (m + 1) for _ in range(n + 1)]
    count = 0

    for i in range(n):
        for j in range(m):
            prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j] + matrix[i][j]

    for i in range(n):
        for j in range(m):
            for k in range(i + 1, n + 1):
                for l in range(j + 1, m + 1):
                    if prefix_sum[k][l] - prefix_sum[i][l] - prefix_sum[k][j] + prefix_sum[i][j] == target:
                        count += 1

    return count


def main():
    n, m, target = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(n)]
    print(count_submatrices_with_sum_equal_to_target(matrix, target))


if __name__ == "__main__":
    main()

This code first calculates the prefix sum of the matrix to find the sum of the submatrices. Then, it checks each submatrix to see if its sum is equal to the target. If it is, it increments the count. The main function reads the number of rows and columns, and the target sum from the input, and then prints the count of the submatrices with sum equal to the target.