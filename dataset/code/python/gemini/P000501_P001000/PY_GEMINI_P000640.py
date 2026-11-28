import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        val = int(tokens[1+n])
        print(*([val] + vals))
if __name__ == '__main__':
    main()