import sys
def comb(n, k, start, cur):
    if len(cur) == k:
        print(*cur)
        return
    for i in range(start, n + 1):
        comb(n, k, i + 1, cur + [i])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n, k = int(tokens[0]), int(tokens[1])
        comb(n, k, 1, [])
if __name__ == '__main__':
    main()