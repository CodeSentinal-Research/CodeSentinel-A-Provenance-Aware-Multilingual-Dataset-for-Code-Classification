import sys

def solve():
    grid = []
    for _ in range(9):
        row = list(map(int, sys.stdin.readline().split()))
        grid.append(row)
        
    def is_valid_sudoku(grid):
        # Check rows
        for i in range(9):
            seen = set()
            for j in range(9):
                if grid[i][j] != 0:
                    if grid[i][j] in seen:
                        return False
                    seen.add(grid[i][j])
                    
        # Check cols
        for j in range(9):
            seen = set()
            for i in range(9):
                if grid[i][j] != 0:
                    if grid[i][j] in seen:
                        return False
                    seen.add(grid[i][j])
                    
        # Check boxes
        for box_r in range(3):
            for box_c in range(3):
                seen = set()
                for i in range(3):
                    for j in range(3):
                        val = grid[box_r*3 + i][box_c*3 + j]
                        if val != 0:
                            if val in seen:
                                return False
                            seen.add(val)
                            
        return True
        
    print("YES" if is_valid_sudoku(grid) else "NO")

if __name__ == "__main__":
    solve()

