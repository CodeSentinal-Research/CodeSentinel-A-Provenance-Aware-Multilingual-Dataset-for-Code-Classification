Here is the Python code for the given problem:

def search_in_matrix(rows, cols, target):
    matrix = []
    for _ in range(rows):
        matrix.append(list(map(int, input().split())))

    for row in matrix:
        if target in row:
            print("Found")
            return
    print("Not Found")

def main():
    rows, cols, target = map(int, input().split())
    search_in_matrix(rows, cols, target)

if __name__ == "__main__":
    main()

In this code, the input is read in the main function, which will be called when the program starts. The input will be a line containing the number of rows and columns, followed by the target value to search for. The rows and columns are then read in a nested loop, which is the main part of the program where the matrix is built and the target is searched for. If the target is found in the matrix, the program prints "Found", otherwise it prints "Not Found".