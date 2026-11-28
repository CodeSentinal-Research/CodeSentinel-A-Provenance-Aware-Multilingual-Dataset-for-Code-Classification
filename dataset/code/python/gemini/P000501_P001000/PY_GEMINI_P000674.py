import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        less = True
        for i in range(n - 1):
            if less:
                if vals[i] > vals[i + 1]: vals[i], vals[i + 1] = vals[i + 1], vals[i]
            else:
                if vals[i] < vals[i + 1]: vals[i], vals[i + 1] = vals[i + 1], vals[i]
            less = not less
        print(*vals)
if __name__ == '__main__':
    main()