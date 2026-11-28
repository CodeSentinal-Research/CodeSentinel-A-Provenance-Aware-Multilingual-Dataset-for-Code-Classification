import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        vals = sorted(int(t) for t in tokens if t not in ("null", "#", "N"))
        print(*vals)
if __name__ == '__main__':
    main()