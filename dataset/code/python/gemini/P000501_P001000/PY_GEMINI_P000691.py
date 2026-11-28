import sys
def gcd_rec(a, b):
    """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
    if b == 0: return a
    return gcd_rec(b, a % b)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        a, b = int(tokens[0]), int(tokens[1])
        print(gcd_rec(a, b))
if __name__ == '__main__':
    main()