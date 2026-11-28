import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        f = float(lines[0])
        c = (f - 32.0) * 5.0 / 9.0
        print(f"{c:.2f}" if c % 1 != 0 else f"{int(c)}")

if __name__ == '__main__':
    main()