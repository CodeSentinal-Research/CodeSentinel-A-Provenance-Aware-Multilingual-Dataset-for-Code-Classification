import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        r = int(tokens[0])
        c = int(tokens[1])
        mat = list(map(int, tokens[2:2+r*c]))
        print(max(mat))
if __name__ == '__main__':
    main()