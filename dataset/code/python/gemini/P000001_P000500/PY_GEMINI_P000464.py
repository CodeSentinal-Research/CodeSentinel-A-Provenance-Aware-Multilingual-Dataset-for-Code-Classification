import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        target = int(tokens[1])
        arr = list(map(int, tokens[2:2+n]))
        closest = min(arr, key=lambda x: (abs(x - target), x))
        print(closest)
if __name__ == '__main__':
    main()