def get_row(rowIndex):
    row = [1]
    for _ in range(rowIndex):
        row = [sum(x) for x in zip([0]+row, row+[0])]
    return row

print(get_row(5))

This Python function uses the formula for Pascal's Triangle to calculate each row of the triangle. It's a standard formula where each number in a row is the sum of the two numbers directly above it.

In the main function, it calls this function with the row index as input. It then prints the resulting row.