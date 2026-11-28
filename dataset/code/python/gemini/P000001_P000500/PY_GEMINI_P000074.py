import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        r = float(lines[0])
        v = (4.0 / 3.0) * 3.14159 * (r ** 3)
        print(f"{v:.5f}")
if __name__ == '__main__':
    main()