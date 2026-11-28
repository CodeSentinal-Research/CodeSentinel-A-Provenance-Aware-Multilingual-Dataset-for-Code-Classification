import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        k = int(tokens[2])
        idx = 3
        a = list(map(int, tokens[idx:idx+m])); idx += m
        b = list(map(int, tokens[idx:idx+n]))
        merged = sorted(a + b)
        print(merged[k - 1])
if __name__ == '__main__':
    main()