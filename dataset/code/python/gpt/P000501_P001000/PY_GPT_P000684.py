# problem title : Fibonacci Number
# Solve the stated task using standard input and standard output.
import sys
def fib_rec(n):
    if n <= 0: return 0
    if n == 1: return 1
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(fib_rec(n))
if __name__ == '__main__':
    main()
