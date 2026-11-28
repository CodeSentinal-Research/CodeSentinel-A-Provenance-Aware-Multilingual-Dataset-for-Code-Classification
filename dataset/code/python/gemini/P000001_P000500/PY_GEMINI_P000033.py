import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        total = sum(i for i in range(1, n + 1) if n % i == 0)
        print(total)
if __name__ == '__main__':
    main()