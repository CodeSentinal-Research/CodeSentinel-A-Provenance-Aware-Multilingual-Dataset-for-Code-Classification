# problem title : Boolean Parenthesization Count
# Solve the stated task using standard input and standard output.
import sys
def count_paren(s):
    memo = {}
    def solve(i, j, is_true):
        if i > j: return 0
        if i == j:
            if is_true: return 1 if s[i] == 'T' else 0
            else: return 1 if s[i] == 'F' else 0
        key = (i, j, is_true)
        if key in memo: return memo[key]
        ans = 0
        for k in range(i + 1, j, 2):
            op = s[k]
            lt = solve(i, k - 1, True)
            lf = solve(i, k - 1, False)
            rt = solve(k + 1, j, True)
            rf = solve(k + 1, j, False)
            if op == '&':
                if is_true: ans += lt * rt
                else: ans += lt * rf + lf * rt + lf * rf
            elif op == '|':
                if is_true: ans += lt * rt + lt * rf + lf * rt
                else: ans += lf * rf
            elif op == '^':
                if is_true: ans += lt * rf + lf * rt
                else: ans += lt * rt + lf * rf
        memo[key] = ans
        return ans
    return solve(0, len(s) - 1, True)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        print(count_paren(tokens[0]))
if __name__ == '__main__':
    main()
