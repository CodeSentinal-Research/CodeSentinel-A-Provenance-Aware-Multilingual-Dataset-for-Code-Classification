import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        bits = tokens[1:1+n]
        print(int("".join(bits), 2))
if __name__ == '__main__':
    main()