import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = float(lines[0])
        print(f"{s * s:.2f}" if (s * s) % 1 != 0 else f"{int(s * s)}")
if __name__ == '__main__':
    main()