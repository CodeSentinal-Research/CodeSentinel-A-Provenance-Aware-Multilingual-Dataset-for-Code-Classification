import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        k = min(k, n)
        vals[:k] = vals[:k][::-1]
        print(*vals)
if __name__ == '__main__':
    main()