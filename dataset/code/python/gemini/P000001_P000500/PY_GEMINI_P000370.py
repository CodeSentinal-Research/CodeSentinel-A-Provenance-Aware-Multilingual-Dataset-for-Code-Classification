import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n+1]))
        seen = set()
        for v in arr:
            if v in seen:
                print(v)
                return
            seen.add(v)
        print(-1)

if __name__ == '__main__':
    main()