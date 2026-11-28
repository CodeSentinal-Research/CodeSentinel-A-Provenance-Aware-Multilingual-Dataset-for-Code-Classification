import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        p, r, t = float(lines[0]), float(lines[1]), float(lines[2])
        a = p * ((1.0 + r / 100.0) ** t)
        ci = a - p
        print(f"{ci:.2f}")
if __name__ == '__main__':
    main()