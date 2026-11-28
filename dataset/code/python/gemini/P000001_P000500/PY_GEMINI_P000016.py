import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        c = float(lines[0])
        f = (c * 9.0 / 5.0) + 32.0
        print(f"{f:.2f}" if f % 1 != 0 else f"{int(f)}")

if __name__ == '__main__':
    main()