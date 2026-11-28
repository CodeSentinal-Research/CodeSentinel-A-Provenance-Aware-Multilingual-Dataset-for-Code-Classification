import sys

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        l, b = float(lines[0]), float(lines[1])
        perimeter = 2 * (l + b)
        print(f"{perimeter:.2f}" if perimeter % 1 != 0 else f"{int(perimeter)}")

if __name__ == '__main__':
    main()