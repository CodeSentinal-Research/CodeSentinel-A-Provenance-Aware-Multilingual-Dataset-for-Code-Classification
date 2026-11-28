import sys
def diff_ways_to_compute(expr):
    res = []
    for i, c in enumerate(expr):
        if c in '+-*':
            left = diff_ways_to_compute(expr[:i])
            right = diff_ways_to_compute(expr[i+1:])
            for l in left:
                for r in right:
                    if c == '+': res.append(l + r)
                    elif c == '-': res.append(l - r)
                    elif c == '*': res.append(l * r)
    if not res:
        res.append(int(expr))
    return res
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        res = sorted(diff_ways_to_compute(tokens[0]))
        print(*res)
if __name__ == '__main__':
    main()