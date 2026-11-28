Here is the Python code for the problem:

def searchInMatrix(matrix, target):
    if not matrix or not isinstance(matrix, list) or not all(isinstance(i, list) for i in matrix):
        return False

    if not matrix[0] or not isinstance(matrix[0], int) or not all(isinstance(i, int) for i in matrix[0]):
        return False

    N = len(matrix)
    M = len(matrix[0])

    row, col = 0, M - 1

    while row < N and col >= 0:
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] > target:
            col -= 1
        else:
            row += 1

    return False

And here is the main function to test the above code:

def main():
    matrix = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]]

    print(searchInMatrix(matrix, 5))  
    print(searchInMatrix(matrix, 20))  

if __name__ == "__main__":
    main()

In the main function, we test the function `searchInMatrix` with two test cases. The first one is when the target exists in the matrix, the second one is when the target does not exist in the matrix. The function `searchInMatrix` returns `True` if the target exists, otherwise `False`.