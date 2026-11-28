import sys
def fact_rec(n):
    if n <= 1: return 1
    return n * fact_rec(n - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(fact_rec(n))
if __name__ == '__main__':
    main()