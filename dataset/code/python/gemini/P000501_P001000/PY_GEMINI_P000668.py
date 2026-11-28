import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        size = int(tokens[0])
        vals = list(map(int, tokens[1:1+size]))
        m = int(tokens[1+size])
        n = int(tokens[2+size])
        res = []
        cur = 0
        while cur < size:
            res.extend(vals[cur:cur+m])
            cur += m + n
        print(*res)
if __name__ == '__main__':
    main()