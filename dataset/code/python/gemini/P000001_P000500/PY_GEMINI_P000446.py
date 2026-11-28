import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        r = int(tokens[0])
        c = int(tokens[1])
        target = int(tokens[2])
        mat = list(map(int, tokens[3:3+r*c]))
        print("Found" if target in mat else "Not Found")
if __name__ == '__main__':
    main()