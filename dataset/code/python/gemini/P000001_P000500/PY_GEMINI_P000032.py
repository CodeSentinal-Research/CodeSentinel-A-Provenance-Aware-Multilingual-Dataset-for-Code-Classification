import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        count = sum(1 for i in range(1, n + 1) if n % i == 0)
        print(count)
if __name__ == '__main__':
    main()