import sys
def prod_digits(n):
    if n < 10: return n
    return (n % 10) * prod_digits(n // 10)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(prod_digits(abs(n)))
if __name__ == '__main__':
    main()