import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        b, h = float(lines[0]), float(lines[1])
        area = 0.5 * b * h
        print(f"{area:.2f}" if area % 1 != 0 else f"{int(area)}")
if __name__ == '__main__':
    main()