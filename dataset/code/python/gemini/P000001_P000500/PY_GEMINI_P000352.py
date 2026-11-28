import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n+1]))
        x = int(tokens[n+1])
        try:
            print(arr.index(x))
        except ValueError:
            print(-1)

if __name__ == '__main__':
    main()