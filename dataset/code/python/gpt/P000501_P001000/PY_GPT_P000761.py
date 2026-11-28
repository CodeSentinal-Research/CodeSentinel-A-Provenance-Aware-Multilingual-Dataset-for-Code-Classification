# problem title : Count Distinct Subsequences
# Solve the stated task using standard input and standard output.
import sys
def num_distinct(s, t):
    memo = {}
    def backtrack(i, j):
        if j == len(t): return 1
        if i == len(s): return 0
        if (i, j) in memo: return memo[(i, j)]
        res = backtrack(i + 1, j)
        if s[i] == t[j]:
            res += backtrack(i + 1, j + 1)
        memo[(i, j)] = res
        return res
    return backtrack(0, 0)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s, t = tokens[0], tokens[1]
        print(num_distinct(s, t))
if __name__ == '__main__':
    main()
