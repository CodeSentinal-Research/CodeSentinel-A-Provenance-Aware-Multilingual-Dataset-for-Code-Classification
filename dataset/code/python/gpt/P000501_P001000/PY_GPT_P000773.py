# problem title : Count Ways to Parenthesize Arithmetic Expression
# Solve the stated task using standard input and standard output.
import sys
def count_max_parenthesize(expr):
    memo = {}
    def solve(i, j):
        if i == j:
            val = int(expr[i])
            return {val: 1}
        if (i, j) in memo: return memo[(i, j)]
        res = {}
        for k in range(i + 1, j, 2):
            op = expr[k]
            left = solve(i, k - 1)
            right = solve(k + 1, j)
            for lv, lcnt in left.items():
                for rv, rcnt in right.items():
                    if op == '+': v = lv + rv
                    elif op == '-': v = lv - rv
                    elif op == '*': v = lv * rv
                    res[v] = res.get(v, 0) + lcnt * rcnt
        memo[(i, j)] = res
        return res
    all_res = solve(0, len(expr) - 1)
    max_v = max(all_res.keys())
    return all_res[max_v]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        print(count_max_parenthesize(tokens[0]))
if __name__ == '__main__':
    main()
