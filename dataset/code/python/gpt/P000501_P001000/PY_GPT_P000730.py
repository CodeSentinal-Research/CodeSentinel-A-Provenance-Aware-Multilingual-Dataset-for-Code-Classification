# problem title : N-Queens
# Solve the stated task using standard input and standard output.
import sys
def solve_n_queens(n):
    cols, diag1, diag2 = set(), set(), set()
    board = [['.']*n for _ in range(n)]
    res = []
    def backtrack(r):
        if r == n:
            res.append(["".join(row) for row in board])
            return
        for c in range(n):
            if c in cols or (r + c) in diag1 or (r - c) in diag2: continue
            cols.add(c); diag1.add(r + c); diag2.add(r - c)
            board[r][c] = 'Q'
            backtrack(r + 1)
            board[r][c] = '.'
            cols.remove(c); diag1.remove(r + c); diag2.remove(r - c)
    backtrack(0)
    return res
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        boards = solve_n_queens(n)
        for b in boards:
            for row in b:
                print(row)
            print()
if __name__ == '__main__':
    main()
