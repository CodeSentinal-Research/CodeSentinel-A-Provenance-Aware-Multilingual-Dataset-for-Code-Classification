import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = float(lines[0])
        print(f"{s ** 3:.2f}" if (s ** 3) % 1 != 0 else f"{int(s ** 3)}")
if __name__ == '__main__':
    main()