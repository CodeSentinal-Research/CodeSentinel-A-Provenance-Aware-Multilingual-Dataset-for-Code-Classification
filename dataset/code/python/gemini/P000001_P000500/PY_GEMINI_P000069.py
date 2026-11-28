import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        r = float(lines[0])
        print(f"{2 * 3.14159 * r:.5f}")
if __name__ == '__main__':
    main()