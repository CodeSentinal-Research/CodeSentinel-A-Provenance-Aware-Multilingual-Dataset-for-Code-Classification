import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        products = tokens[1:n+1]
        suffix = tokens[n+1]
        for p in products:
            if p.endswith(suffix):
                print(p)
if __name__ == '__main__':
    main()