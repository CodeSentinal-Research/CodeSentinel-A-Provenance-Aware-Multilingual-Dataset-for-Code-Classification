# problem title : Decimal to Binary Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def dec_to_bin(n):
    if n == 0: return "0"
    if n == 1: return "1"
    return dec_to_bin(n // 2) + str(n % 2)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(dec_to_bin(n))
if __name__ == '__main__':
    main()
