# problem title : Scramble String
# Solve the stated task using standard input and standard output.
import sys
def is_scramble(s1, s2):
    memo = {}
    def solve(a, b):
        if a == b: return True
        if sorted(a) != sorted(b): return False
        key = (a, b)
        if key in memo: return memo[key]
        n = len(a)
        for i in range(1, n):
            if (solve(a[:i], b[:i]) and solve(a[i:], b[i:])) or (solve(a[:i], b[n-i:]) and solve(a[i:], b[:n-i])):
                memo[key] = True
                return True
        memo[key] = False
        return False
    return solve(s1, s2)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s1, s2 = tokens[0], tokens[1]
        print("true" if is_scramble(s1, s2) else "false")
if __name__ == '__main__':
    main()
