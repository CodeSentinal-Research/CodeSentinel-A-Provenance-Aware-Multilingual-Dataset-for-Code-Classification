# problem title : Power Function Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def power_rec(x, n):
    if n == 0: return 1
    if n < 0: return 1 / power_rec(x, -n)
    half = power_rec(x, n // 2)
    return half * half * (x if n % 2 != 0 else 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        x = float(tokens[0]) if '.' in tokens[0] else int(tokens[0])
        n = int(tokens[1])
        res = power_rec(x, n)
        if isinstance(res, float) and res.is_integer(): res = int(res)
        print(res)
if __name__ == '__main__':
    main()
