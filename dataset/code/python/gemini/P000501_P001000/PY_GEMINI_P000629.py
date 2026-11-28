import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        if k == 1:
            return
        res = [vals[i] for i in range(n) if (i + 1) % k != 0]
        print(*res)
if __name__ == '__main__':
    main()