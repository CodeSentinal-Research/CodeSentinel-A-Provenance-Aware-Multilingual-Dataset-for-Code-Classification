import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        if 1 <= k <= n:
            print(vals[n - k])
        else:
            print(-1)
if __name__ == '__main__':
    main()