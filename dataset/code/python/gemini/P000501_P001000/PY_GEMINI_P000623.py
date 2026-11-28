import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        res = []
        reverse = True
        for i in range(0, n, k):
            chunk = vals[i:i+k]
            if reverse:
                res.extend(chunk[::-1])
            else:
                res.extend(chunk)
            reverse = not reverse
        print(*res)
if __name__ == '__main__':
    main()