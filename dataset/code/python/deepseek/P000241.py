Here is the Python code for the problem:

def find_saddle_point(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if min(matrix[i]) == matrix[i][j] and max(column[j]) == matrix[i][j]:
                return (i, j)
    return "No Saddle Point"

def main():
    N = int(input().strip())
    matrix = []
    for _ in range(N):
        matrix.append(list(map(int, input().strip().split())))
    print(find_saddle_point(matrix))

if __name__ == "__main__":
    main()

This program first reads the size of the matrix from the standard input, then it reads the matrix from the standard input. The `find_saddle_point` function iterates over the matrix and returns the coordinates of the first saddle point it finds. If no saddle point is found, it returns "No Saddle Point".

The `main` function is the entry point of the program. It reads the size of the matrix, then reads the matrix, and finally prints the result of `find_saddle_point`.