import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        res = []
        for i in range(n):
            c = sum(1 for j in range(i + 1, n) if arr[j] < arr[i])
            res.append(c)
        print(*res)
if __name__ == '__main__':
    main()