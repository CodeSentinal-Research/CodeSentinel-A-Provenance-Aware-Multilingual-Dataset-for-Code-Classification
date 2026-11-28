import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        print(' '.join(str(i) for i in range(n, 0, -1)))
if __name__ == '__main__':
    main()