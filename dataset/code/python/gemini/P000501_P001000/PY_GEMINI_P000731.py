import sys
def total_n_queens(n):
    cols, diag1, diag2 = set(), set(), set()
    count = [0]
    def backtrack(r):
        if r == n:
            count[0] += 1
            return
        for c in range(n):
            if c in cols or (r + c) in diag1 or (r - c) in diag2: continue
            cols.add(c); diag1.add(r + c); diag2.add(r - c)
            backtrack(r + 1)
            cols.remove(c); diag1.remove(r + c); diag2.remove(r - c)
    backtrack(0)
    return count[0]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(total_n_queens(n))
if __name__ == '__main__':
    main()