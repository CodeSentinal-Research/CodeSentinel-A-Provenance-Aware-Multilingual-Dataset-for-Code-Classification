import sys

def solve():
    grid = []
    for _ in range(9):
        row = list(map(int, sys.stdin.readline().split()))
        grid.append(row)
        
    def is_valid(grid, row, col, num):
        for i in range(9):
            if grid[row][i] == num or grid[i][col] == num:
                return False
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if grid[start_row + i][start_col + j] == num:
                    return False
        return True
        
    def solve_sudoku(grid):
        for i in range(9):
            for j in range(9):
                if grid[i][j] == 0:
                    for num in range(1, 10):
                        if is_valid(grid, i, j, num):
                            grid[i][j] = num
                            if solve_sudoku(grid):
                                return True
                            grid[i][j] = 0
                    return False
        return True
        
    if solve_sudoku(grid):
        for row in grid:
            print(" ".join(map(str, row)))

if __name__ == "__main__":
    solve()

