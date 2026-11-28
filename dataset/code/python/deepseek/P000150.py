Here is the Python code that does the sorting:

def sort_matrix(rows, cols, matrix):
    flattened_matrix = [item for sublist in matrix for item in sublist]

    sorted_matrix = sorted(flattened_matrix)

    sorted_matrix = [sorted_matrix[i*cols : (i+1)*cols] for i in range(rows)]

    return sorted_matrix

rows, cols = map(int, input().split())
matrix = []
for _ in range(rows):
    matrix.append(list(map(int, input().split())))

print(sort_matrix(rows, cols, matrix))

This code first reads the matrix from the input. It then flattens the matrix and sorts the flattened matrix. It then reconstructs the sorted matrix and prints it.