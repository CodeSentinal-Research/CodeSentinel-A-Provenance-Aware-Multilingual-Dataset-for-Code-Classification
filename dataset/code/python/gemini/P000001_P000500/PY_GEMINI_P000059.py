import sys, functools, operator
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0].lstrip('-')
        prod = functools.reduce(operator.mul, [int(ch) for ch in s if ch.isdigit()], 1)
        print(prod)
if __name__ == '__main__':
    main()