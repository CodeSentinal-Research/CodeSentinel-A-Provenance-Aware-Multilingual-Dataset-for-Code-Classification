def maximal_rectangle(matrix):
    if not matrix or not matrix[0]:
        return 0

    rows, cols = len(matrix), len(matrix[0])
    height = [0] * cols
    max_area = 0

    for row in matrix:
        for i in range(cols):
            if row[i] == 1:
                height[i] += 1
            else:
                height[i] = 0
        max_area = max(max_area, max_area_hist(height))

    return max_area

def max_area_hist(height):
    stack = []
    max_area = 0

    for i in range(len(height)):
        while stack and height[i] < height[stack[-1]]:
            j = stack.pop()
            max_area = max(max_area, height[i] * (i - stack[-1] - 1))
            height[i] = height[j]
        stack.append(i)

    while stack:
        j = stack.pop()
        max_area = max(max_area, height[j] * (len(height) - stack[-1] - 1))

    return max_area

def input_matrix():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    matrix = []

    for i in range(rows):
        row = [int(x) for x in input(f"Enter the {i+1} row ({cols} numbers): ").split()]
        matrix.append(row)

    return matrix

def main():
    matrix = input_matrix()
    print(f"The maximum area of the rectangle is {maximal_rectangle(matrix)}")

if __name__ == "__main__":
    main()