import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        try:
            print(arr.index(1))
        except ValueError:
            print(-1)
if __name__ == '__main__':
    main()