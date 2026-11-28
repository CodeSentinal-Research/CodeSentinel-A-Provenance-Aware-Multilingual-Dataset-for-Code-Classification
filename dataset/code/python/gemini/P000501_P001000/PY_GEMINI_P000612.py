import sys
import math
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        res = []
        for i in range(n):
            res.append(vals[i])
            if i + 1 < n:
                res.append(math.gcd(vals[i], vals[i + 1]))
        print(*res)
if __name__ == '__main__':
    main()