import sys
def sum_digits(n):
    if n == 0: return 0
    return (n % 10) + sum_digits(n // 10)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(sum_digits(abs(n)))
if __name__ == '__main__':
    main()