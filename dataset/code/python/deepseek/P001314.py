Here is the Python code to validate Sudoku solution.

def is_valid_sudoku(puzzle):
    rows = [set(row) for row in puzzle]
    cols = [set(col) for col in zip(*puzzle)]
    squares = [set(puzzle[i][j] for i in range(3 * (j // 3), 3 * (j // 3) + 3)) for j in range(9)]

    if any(row.intersection(rows[i]) for i, row in enumerate(rows)) or \
       any(col.intersection(cols[i]) for i, col in enumerate(cols)) or \
       any(square.intersection(squares[i]) for i, square in enumerate(squares)):
        return False
    return True

def main():
    puzzle = []
    for _ in range(9):
        row = list(map(int, input().split()))
        puzzle.append(row)

    if is_valid_sudoku(puzzle):
        print('YES')
    else:
        print('NO')


if __name__ == "__main__":
    main()

In the above code, we first define a function `is_valid_sudoku` which takes a 9x9 list of lists as input. This function checks if the 9x9 grid contains any repeated numbers. If it does, it returns False, otherwise True.

In the main function, we read the 9x9 grid from the standard input. If the grid is valid, we print 'YES', otherwise 'NO'.

To run this program, you can use the following command:

python3 your_program.py

Please replace `your_program.py` with the actual name of your Python file. The program reads a 9x9 grid from the standard input, and prints 'YES' if the grid is valid, and 'NO' otherwise.