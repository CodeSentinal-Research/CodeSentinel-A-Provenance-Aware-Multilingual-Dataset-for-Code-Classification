import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = tokens[1:1+n]
        N = int(tokens[1+n])
        res = [vals[i] for i in range(n) if (i + 1) % N != 0]
        print(*res)
if __name__ == '__main__':
    main()