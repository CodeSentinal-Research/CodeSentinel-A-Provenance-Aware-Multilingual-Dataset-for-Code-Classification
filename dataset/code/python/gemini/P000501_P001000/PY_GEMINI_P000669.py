import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        if n == 0:
            print(-1)
        else:
            vals = list(map(int, tokens[1:1+n]))
            print(min(vals))
    else:
        print(-1)
if __name__ == '__main__':
    main()