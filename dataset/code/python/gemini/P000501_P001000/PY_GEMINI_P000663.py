import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        l1 = list(map(int, tokens[1:1+n]))
        m = int(tokens[1+n])
        l2 = list(map(int, tokens[2+n:2+n+m]))
        res = sorted(l1 + l2)
        print(*res)
if __name__ == '__main__':
    main()