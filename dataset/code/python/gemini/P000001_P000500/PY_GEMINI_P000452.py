import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        ans = 0
        for v in arr: ans ^= v
        print(ans)
if __name__ == '__main__':
    main()