import sys

def diff_ways_to_compute(expression: str):
    memo = {}
    def dfs(expr):
        if expr in memo:
            return memo[expr]
        res = []
        for i, c in enumerate(expr):
            if c in "+-*":
                left = dfs(expr[:i])
                right = dfs(expr[i+1:])
                for l in left:
                    for r in right:
                        if c == '+': res.append(l + r)
                        elif c == '-': res.append(l - r)
                        elif c == '*': res.append(l * r)
        if not res:
            res.append(int(expr))
        memo[expr] = res
        return res
    return dfs(expression)

def main():
    lines = sys.stdin.read().split()
    if lines:
        for val in diff_ways_to_compute(lines[0]):
            print(val)

if __name__ == '__main__':
    main()