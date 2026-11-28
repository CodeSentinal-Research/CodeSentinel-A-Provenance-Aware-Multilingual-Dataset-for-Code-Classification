import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        names = tokens[1:n+1]
        prefix = tokens[n+1]
        for name in names:
            if name.startswith(prefix):
                print(name)

if __name__ == '__main__':
    main()