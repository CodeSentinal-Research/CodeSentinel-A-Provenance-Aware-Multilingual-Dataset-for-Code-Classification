def matrix_power(N, K, A):
    I = [[1 if row == col else 0 for col in range(N)] for row in range(N)]

    while K > 0:
        if K % 2 == 1:
            I = [[sum(I[row][j] * A[row][k] for k in range(N)) for j in range(N)] for row in range(N)]
        K = K // 2
        A = [[sum(A[row][k] * A[k][col] for k in range(N)) for col in range(N)] for row in range(N)]

    return I

def main():
    N = int(input('Enter the size of the matrix: '))
    K = int(input('Enter the power to raise the matrix to: '))
    A = [[int(input(f'Enter the element at position ({row},{col}): ')) for col in range(N)] for row in range(N)]

    result = matrix_power(N, K, A)
    print('The matrix A raised to the power K is: ')
    for row in result:
        print(row)

if __name__ == '__main__':
    main()