def input_matrix():
    while True:
        try:
            N, M = map(int, input("Enter the dimensions of matrix A (N x M): ").split())
            break
        except ValueError:
            print("Invalid input. Please enter two positive integers.")

    matrix_a = []
    print("Enter the matrix A:")
    for _ in range(N):
        row = list(map(int, input().split()))
        matrix_a.append(row)

    while True:
        try:
            M, P = map(int, input("Enter the dimensions of matrix B (M x P): ").split())
            break
        except ValueError:
            print("Invalid input. Please enter two positive integers.")

    matrix_b = []
    print("Enter the matrix B:")
    for _ in range(M):
        row = list(map(int, input().split()))
        matrix_b.append(row)

    return matrix_a, matrix_b


def sparse_matrix_mult(matrix_a, matrix_b):
    product = [[0 for _ in range(P)] for _ in range(N)]

    for i in range(N):
        for j in range(P):
            sum_ = 0
            for k in range(M):
                sum_ += matrix_a[i][k] * matrix_b[k][j]
            product[i][j] = sum_

    return product


def main():
    matrix_a, matrix_b = input_matrix()
    product = sparse_matrix_mult(matrix_a, matrix_b)

    print("\nProduct of the matrices is:")
    for row in product:
        print(row)


if __name__ == "__main__":
    main()