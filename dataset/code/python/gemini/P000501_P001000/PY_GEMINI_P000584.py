import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        size = int(tokens[0])
        vals = list(map(int, tokens[1:1+size]))
        n = int(tokens[1+size])
        idx = size - n
        vals.pop(idx)
        print(*vals)
if __name__ == '__main__':
    main()