import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        q = list(map(int, tokens[1:1+n]))
        print(*q[::-1])
if __name__ == '__main__':
    main()