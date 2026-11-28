import sys

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        p, r, t = float(lines[0]), float(lines[1]), float(lines[2])
        si = (p * r * t) / 100.0
        print(f"{si:.2f}" if si % 1 != 0 else f"{int(si)}")

if __name__ == '__main__':
    main()