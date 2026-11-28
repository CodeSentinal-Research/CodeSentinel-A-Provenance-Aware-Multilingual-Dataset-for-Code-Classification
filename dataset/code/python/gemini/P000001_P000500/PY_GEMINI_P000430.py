import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        for i in range(n - 1, -1, -1):
            if arr[i] == target:
                print(i)
                return
        print(-1)
if __name__ == '__main__':
    main()