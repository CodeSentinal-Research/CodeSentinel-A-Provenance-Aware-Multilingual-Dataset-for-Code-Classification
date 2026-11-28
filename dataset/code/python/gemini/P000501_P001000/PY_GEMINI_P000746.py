import sys
def josephus(n, k):
    if n == 1: return 1
    return (josephus(n - 1, k) + k - 1) % n + 1
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n, k = int(tokens[0]), int(tokens[1])
        print(josephus(n, k))
if __name__ == '__main__':
    main()