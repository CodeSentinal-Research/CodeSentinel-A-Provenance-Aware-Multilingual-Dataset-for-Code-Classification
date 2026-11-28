# problem title : Count Digits Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def count_digits(n):
    if n < 10: return 1
    return 1 + count_digits(n // 10)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(count_digits(abs(n)))
if __name__ == '__main__':
    main()
