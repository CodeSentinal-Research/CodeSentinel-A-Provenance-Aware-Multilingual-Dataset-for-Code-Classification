Here is the Python code:

def check_symmetric(matrix):
    return matrix == matrix.transpose()

def main():
    N = int(input().strip())
    matrix = [list(map(int, input().strip().split())) for _ in range(N)]
    if check_symmetric(matrix):
        print(True)
    else:
        print(False)

if __name__ == "__main__":
    main()

This program reads a square matrix from the standard input. It then prints out 'True' if the matrix is symmetric about its main diagonal, and 'False' otherwise.