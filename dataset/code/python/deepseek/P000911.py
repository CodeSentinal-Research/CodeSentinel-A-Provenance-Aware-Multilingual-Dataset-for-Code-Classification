Here is the Python code for generating Pascal's Triangle:

def generatePascalsTriangle(numRows):
    pascal_triangle = [[0 for x in range(y+1)] for y in range(numRows)]

    for i in range(numRows):
        for j in range(i+1):
            if j in (0, i) or j == i:
                pascal_triangle[i][j] = 1
            else:
                pascal_triangle[i][j] = (pascal_triangle[i-1][j-1] +
                                          pascal_triangle[i-1][j])

    return pascal_triangle

def main():
    numRows = int(input("Enter the number of rows: "))
    if numRows < 1 or numRows > 30:
        print("Invalid input, please enter a number between 1 and 30.")
        return
    triangle = generatePascalsTriangle(numRows)
    print("Pascal's Triangle:")
    for i in range(numRows):
        print(triangle[i])

if __name__ == "__main__":
    main()

In the `generatePascalsTriangle()` function, we use list comprehension to generate the Pascal's triangle. For each row `i`, we set all values in the row to 1, except for the first and last value, which are set to 1. For the other values, we calculate the value at `(pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j])`.

In the `main()` function, we get the number of rows from user input, check if it's between 1 and 30, and generate the Pascal's triangle if it's valid.