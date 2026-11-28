# problem title : Regular Expression Matching
# Solve the stated task using standard input and standard output.
import sys
def is_match(s, p):
    memo = {}
    def backtrack(i, j):
        if (i, j) in memo: return memo[(i, j)]
        if j == len(p): return i == len(s)
        first_match = (i < len(s)) and (p[j] == s[i] or p[j] == '.')
        if j + 1 < len(p) and p[j + 1] == '*':
            res = backtrack(i, j + 2) or (first_match and backtrack(i + 1, j))
        else:
            res = first_match and backtrack(i + 1, j + 1)
        memo[(i, j)] = res
        return res
    return backtrack(0, 0)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        p = tokens[1] if len(tokens) > 1 else ""
        print("true" if is_match(s, p) else "false")
if __name__ == '__main__':
    main()
