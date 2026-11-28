import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        r, h = float(lines[0]), float(lines[1])
        v = 3.14159 * (r ** 2) * h
        print(f"{v:.5f}")
if __name__ == '__main__':
    main()