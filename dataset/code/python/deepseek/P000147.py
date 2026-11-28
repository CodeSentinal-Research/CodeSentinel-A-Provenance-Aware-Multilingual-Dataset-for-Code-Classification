Sure, here is a Python solution for the problem:

def print_diagonal_elements():
    N = int(input().strip())
    matrix = []
    for i in range(N):
        matrix.append(list(map(int, input().strip().split())))

    main_diagonal = []
    anti_diagonal = []

    for i in range(N):
        for j in range(N):
            if i == j:
                main_diagonal.append(matrix[i][j])
            if i + j == N - 1:
                anti_diagonal.append(matrix[i][j])

    print('Main diagonal: ', main_diagonal)
    print('Anti-diagonal: ', anti_diagonal)


print_diagonal_elements()

This program first reads the size of the matrix N from the input. It then reads the matrix from the input. After that, two empty lists are created to store the main diagonal and anti-diagonal elements.

Then, for each element in the matrix, if the element is on the main diagonal (i.e., if the row index equals the column index), it is added to the main diagonal list. If the element is on the anti-diagonal (i.e., if the row index plus the column index equals N - 1), it is added to the anti-diagonal list.

Finally, the main diagonal and anti-diagonal lists are printed.