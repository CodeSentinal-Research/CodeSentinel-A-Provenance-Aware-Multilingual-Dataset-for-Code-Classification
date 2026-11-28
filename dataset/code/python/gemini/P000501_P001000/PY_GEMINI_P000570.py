import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        q = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n]) % n
        q = q[k:] + q[:k]
        print(*q)
if __name__ == '__main__':
    main()