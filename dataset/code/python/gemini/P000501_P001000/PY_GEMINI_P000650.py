import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        size = int(tokens[0])
        vals = list(map(int, tokens[1:1+size]))
        n = int(tokens[1+size])
        if 1 <= n <= size:
            print(vals[n - 1])
        else:
            print(-1)
if __name__ == '__main__':
    main()