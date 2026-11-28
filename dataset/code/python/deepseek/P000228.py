Here is the Python code:

def search_in_sorted_matrix(rows, cols, target):
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))
    for row in matrix:
        for elem in row:
            if elem == target:
                return "Found"
    return "Not Found"

def main():
    rows, cols, target = map(int, input().split())
    print(search_in_sorted_matrix(rows, cols, target))

if __name__ == "__main__":
    main()

This code first reads the number of rows and columns, then the target value. It then reads the matrix row by row and checks if the target value is present in each row. If the target value is found in any row, it returns "Found". If it is not found in any row, it returns "Not Found".