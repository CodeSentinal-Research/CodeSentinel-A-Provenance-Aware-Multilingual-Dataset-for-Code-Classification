import sys

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        a, b, c = int(lines[0]), int(lines[1]), int(lines[2])
        print(max(a, b, c))

if __name__ == '__main__':
    main()