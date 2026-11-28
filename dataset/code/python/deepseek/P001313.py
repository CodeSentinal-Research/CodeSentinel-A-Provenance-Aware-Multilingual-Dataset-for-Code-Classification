Here is the Python code for the problem:

def solve_sudoku(grid):
    empty = find_empty(grid)
    if not empty:
        return True
    else:
        row, col = empty

    for i in range(1,10):
        if valid(grid, i, (row, col)):
            grid[row][col] = i

            if solve_sudoku(grid):
                return True

            grid[row][col] = 0

    return False


def find_empty(grid):
    for i in range(9):
        for j in range(9):
            if grid[i][j] == 0:
                return i, j  
    return None


def valid(grid, num, pos):
    for i in range(len(grid[0])):
        if grid[pos[0]][i] == num and pos[1] != i:
            return False

    for i in range(len(grid)):
        if grid[i][pos[1]] == num and pos[0] != i:
            return False

    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y*3, box_y*3 + 3):
        for j in range(box_x * 3, box_x*3 + 3):
            if grid[i][j] == num and (i,j) != pos:
                return False

    return True


def print_sudoku(grid):
    for i in range(len(grid)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - - -")
        for j in range(len(grid[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")
            if j == 8:
                print(grid[i][j])
            else:
                print(str(grid[i][j]) + " ", end="")


def main():
    sudoku_str = [input().split() for _ in range(9)]
    sudoku = [ [int(num) for num in row] for row in sudoku_str]

    print_sudoku(sudoku)

    solve_sudoku(sudoku)

    print("\n")
    print_sudoku(sudoku)


if __name__ == '__main__':
    main()

In this program, we first input the Sudoku puzzle as a 2D list of integers. Then, we call the `main` function. It first prints the initial Sudoku, solves it using the `solve_sudoku` function, and then prints the solved Sudoku.