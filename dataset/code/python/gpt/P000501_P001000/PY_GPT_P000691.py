# problem title : Greatest Common Divisor Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def gcd_rec(a, b):
    if b == 0: return a
    return gcd_rec(b, a % b)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        a, b = int(tokens[0]), int(tokens[1])
        print(gcd_rec(a, b))
if __name__ == '__main__':
    main()
