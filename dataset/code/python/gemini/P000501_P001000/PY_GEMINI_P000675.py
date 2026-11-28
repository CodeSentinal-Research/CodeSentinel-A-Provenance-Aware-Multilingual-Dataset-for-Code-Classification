import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0]) if tokens[0].isdigit() and len(tokens) - 1 == int(tokens[0]) else len(tokens)
        vals = tokens[1:1+n] if n != len(tokens) else tokens
        print(*(vals[::-1]))
if __name__ == '__main__':
    main()