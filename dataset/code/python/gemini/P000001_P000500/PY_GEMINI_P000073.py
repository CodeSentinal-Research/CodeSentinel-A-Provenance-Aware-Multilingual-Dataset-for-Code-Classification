import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        l, b, h = float(lines[0]), float(lines[1]), float(lines[2])
        v = l * b * h
        print(f"{v:.2f}" if v % 1 != 0 else f"{int(v)}")
if __name__ == '__main__':
    main()