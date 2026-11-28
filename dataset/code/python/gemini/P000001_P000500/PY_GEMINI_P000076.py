import sys, math
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        a, b, c = float(lines[0]), float(lines[1]), float(lines[2])
        d = b * b - 4 * a * c
        if d > 0:
            r1 = (-b + math.sqrt(d)) / (2 * a)
            r2 = (-b - math.sqrt(d)) / (2 * a)
            print(f"{r1:.2f} {r2:.2f}")
        elif d == 0:
            r = -b / (2 * a)
            print(f"{r:.2f}")
        else:
            print("Complex Roots")
if __name__ == '__main__':
    main()