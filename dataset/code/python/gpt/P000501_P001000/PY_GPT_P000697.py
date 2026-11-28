# problem title : Check if Number is Prime Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def is_prime_rec(n, d=2):
    if n <= 1: return False
    if d * d > n: return True
    if n % d == 0: return False
    return is_prime_rec(n, d + 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print("true" if is_prime_rec(n) else "false")
if __name__ == '__main__':
    main()
