import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        q = int(tokens[1+n])
        idx = 2 + n
        for _ in range(q):
            l, r = int(tokens[idx]), int(tokens[idx+1])
            print(r - l + 1)
            idx += 2
if __name__ == '__main__':
    main()