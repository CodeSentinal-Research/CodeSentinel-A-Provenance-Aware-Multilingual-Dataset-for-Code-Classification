Here is a Python solution for your problem:

def read_matrix():
    n, m = map(int, input().split())
    matrix = [[int(j) for j in input().split()] for i in range(n)]
    return matrix

def multiply_matrices(matrix1, matrix2):
    product = [[sum(a*b for a,b in zip(row,col)) for row in matrix1] for col in zip(*matrix2)]
    return product

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

def main():
    matrix1 = read_matrix()
    matrix2 = read_matrix()
    product = multiply_matrices(matrix1, matrix2)
    print_matrix(product)

if __name__ == "__main__":
    main()
In this code, we first read the dimensions of the matrices and then the actual matrices. After that, we multiply the two matrices using the zip function, which combines rows from both matrices, and sum up the products of these combinations.