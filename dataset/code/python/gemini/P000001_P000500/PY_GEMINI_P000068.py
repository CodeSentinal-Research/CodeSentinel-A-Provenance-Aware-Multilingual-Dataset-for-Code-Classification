import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = float(lines[0])
        print(f"{4 * s:.2f}" if (4 * s) % 1 != 0 else f"{int(4 * s)}")
if __name__ == '__main__':
    main()