# problem title : Generate All Valid Arithmetic Expressions
# Solve the stated task using standard input and standard output.
import sys
def diff_ways(expr):
    res = []
    for i, c in enumerate(expr):
        if c in '+-*':
            left = diff_ways(expr[:i])
            right = diff_ways(expr[i+1:])
            for l in left:
                for r in right:
                    res.append(f"({l}{c}{r})")
    if not res:
        res.append(expr)
    return res
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        expr = tokens[0]
        res = sorted(set(diff_ways(expr)))
        for e in res:
            print(e)
if __name__ == '__main__':
    main()
