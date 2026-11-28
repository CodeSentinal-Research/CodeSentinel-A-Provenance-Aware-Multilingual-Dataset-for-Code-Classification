import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        target = int(tokens[0])
        arr = list(map(int, tokens[1:]))
        try:
            print(arr.index(target))
        except ValueError:
            print(-1)
if __name__ == '__main__':
    main()