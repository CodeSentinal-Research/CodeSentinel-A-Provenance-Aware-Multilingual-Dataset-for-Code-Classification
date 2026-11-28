import sys, math
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 4:
        x1, y1, x2, y2 = float(lines[0]), float(lines[1]), float(lines[2]), float(lines[3])
        dist = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
        print(f"{dist:.2f}")
if __name__ == '__main__':
    main()