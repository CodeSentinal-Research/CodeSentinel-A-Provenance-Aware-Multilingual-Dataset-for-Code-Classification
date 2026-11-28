Here is the Python code for the problem:

def search_in_2D_matrix(rows, cols, target, matrix):
    for row in matrix:
        if row[0] == cols and row[1] == target:
            return "Found"
    return "Not Found"

def main():
    input_data = input().split()
    rows = int(input_data[0])
    cols = int(input_data[1])
    target = int(input_data[2])

    matrix = []
    for _ in range(rows):
        row = list(map(int, input().split()))
        matrix.append(row)

    print(search_in_2D_matrix(rows, cols, target, matrix))

if __name__ == "__main__":
    main()

This program first reads the number of rows, columns, and target from the input. Then it reads the matrix from the input. The `search_in_2D_matrix` function iterates through the matrix and checks if the target is in any row. If it is, it returns "Found", otherwise it returns "Not Found". The `main` function calls this function and prints the result.