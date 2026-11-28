import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        a, b, c = float(lines[0]), float(lines[1]), float(lines[2])
        avg = (a + b + c) / 3.0
        print(f"{avg:.2f}" if avg % 1 != 0 else f"{int(avg)}")
if __name__ == '__main__':
    main()