# problem title : Sum of First N Natural Numbers
# Solve the stated task using standard input and standard output.
import sys
def sum_rec(n):
    if n <= 0: return 0
    return n + sum_rec(n - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(sum_rec(n))
if __name__ == '__main__':
    main()
