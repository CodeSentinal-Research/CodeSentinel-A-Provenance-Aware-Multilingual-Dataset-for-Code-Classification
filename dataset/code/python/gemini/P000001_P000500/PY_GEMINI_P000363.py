import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n+1]))
        x = int(tokens[n+1])
        for i, val in enumerate(arr):
            if val < x:
                print(i)
                return
        print(-1)

if __name__ == '__main__':
    main()