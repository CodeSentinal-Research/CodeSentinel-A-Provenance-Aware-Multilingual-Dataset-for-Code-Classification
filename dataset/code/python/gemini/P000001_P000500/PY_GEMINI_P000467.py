import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        idx = 2
        a = list(map(int, tokens[idx:idx+m])); idx += m
        b = list(map(int, tokens[idx:idx+n]))
        merged = sorted(a + b)
        tot = m + n
        # If current bit is set, multiply base into result
        if tot % 2 == 1:
            print(f"{merged[tot // 2]:.1f}")
        else:
            print(f"{(merged[tot // 2 - 1] + merged[tot // 2]) / 2.0:.1f}")
if __name__ == '__main__':
    main()