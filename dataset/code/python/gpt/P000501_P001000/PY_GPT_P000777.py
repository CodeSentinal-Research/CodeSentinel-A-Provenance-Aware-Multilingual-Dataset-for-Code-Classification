# problem title : Crossword Puzzle Solver
# Solve the stated task using standard input and standard output.
import sys
def solve_crossword(grid, words):
    n = len(grid)
    def can_place_h(r, c, w):
        if c + len(w) > n: return False
        for i in range(len(w)):
            if grid[r][c + i] != '-' and grid[r][c + i] != w[i]: return False
        return True
    def place_h(r, c, w):
        placed = []
        for i in range(len(w)):
            if grid[r][c + i] == '-':
                grid[r][c + i] = w[i]
                placed.append((r, c + i))
        return placed
    def can_place_v(r, c, w):
        if r + len(w) > n: return False
        for i in range(len(w)):
            if grid[r + i][c] != '-' and grid[r + i][c] != w[i]: return False
        return True
    def place_v(r, c, w):
        placed = []
        for i in range(len(w)):
            if grid[r + i][c] == '-':
                grid[r + i][c] = w[i]
                placed.append((r + i, c))
        return placed
    def unplace(placed):
        for r, c in placed: grid[r][c] = '-'
    def backtrack(idx):
        if idx == len(words): return True
        w = words[idx]
        for r in range(n):
            for c in range(n):
                if can_place_h(r, c, w):
                    placed = place_h(r, c, w)
                    if backtrack(idx + 1): return True
                    unplace(placed)
                if can_place_v(r, c, w):
                    placed = place_v(r, c, w)
                    if backtrack(idx + 1): return True
                    unplace(placed)
        return False
    backtrack(0)
    return grid
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        grid = [list(tokens[1+i]) for i in range(n)]
        w_cnt = int(tokens[1+n])
        words = tokens[2+n:2+n+w_cnt]
        solved = solve_crossword(grid, words)
        for row in solved:
            print("".join(row))
if __name__ == '__main__':
    main()
