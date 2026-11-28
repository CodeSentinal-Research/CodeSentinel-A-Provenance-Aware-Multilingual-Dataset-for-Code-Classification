import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        total = n * (n + 1) // 2
        print(total)

if __name__ == '__main__':
    main()