def searchMatrix(matrix, target):
    if not matrix or not isinstance(matrix, list) or not all(isinstance(i, list) for i in matrix):
        return False

    rows = len(matrix)
    if rows == 0:
        return False

    cols = len(matrix[0])
    if cols == 0:
        return False

    low, high = 0, rows * cols

    while low < high:
        mid = (low + high) // 2
        r, c = divmod(mid, cols)

        if matrix[r][c] < target:
            low = mid + 1
        else:
            high = mid

    return low != high

The code above first checks if the input is a valid matrix. It then uses binary search to find the target value in the matrix. In each iteration of the binary search, it calculates the midpoint and finds the row and column of the target value. If the target is greater than the middle element, it sets the low boundary to mid + 1. Otherwise, it sets the high boundary to mid. The loop continues until the low and high boundaries cross.