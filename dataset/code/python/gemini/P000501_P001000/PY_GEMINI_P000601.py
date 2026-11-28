import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        width, rem = divmod(n, k)
        parts = []
        cur = 0
        for i in range(k):
            size = width + (1 if i < rem else 0)
            parts.append(vals[cur:cur+size])
            cur += size
        for p in parts:
            print(" ".join(map(str, p)) if p else "[]")
if __name__ == '__main__':
    main()