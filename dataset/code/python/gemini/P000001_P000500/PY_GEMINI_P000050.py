import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        print(n * n * n)
if __name__ == '__main__':
    main()