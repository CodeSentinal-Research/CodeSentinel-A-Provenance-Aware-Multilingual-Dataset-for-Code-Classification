import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        res = []
        for v in vals:
            if not res or res[-1] != v:
                res.append(v)
        print(*res)
if __name__ == '__main__':
    main()