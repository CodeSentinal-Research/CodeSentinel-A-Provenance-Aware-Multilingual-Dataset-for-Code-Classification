import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        res = []
        for x in vals:
            if not res or res[-1] != x:
                res.append(x)
        print(*res)
if __name__ == '__main__':
    main()