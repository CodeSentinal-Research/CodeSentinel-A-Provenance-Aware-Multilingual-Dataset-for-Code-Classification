import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        scored, total = float(lines[0]), float(lines[1])
        pct = (scored / total) * 100.0
        print(f"{pct:.2f}")
if __name__ == '__main__':
    main()