# problem title : Wildcard Pattern Matching
# Solve the stated task using standard input and standard output.
import sys
def is_match(s, p):
    memo = {}
    def backtrack(i, j):
        if (i, j) in memo: return memo[(i, j)]
        if j == len(p): return i == len(s)
        if i == len(s): return all(c == '*' for c in p[j:])
        if p[j] in (s[i], '?'):
            res = backtrack(i + 1, j + 1)
        elif p[j] == '*':
            res = backtrack(i + 1, j) or backtrack(i, j + 1)
        else:
            res = False
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
