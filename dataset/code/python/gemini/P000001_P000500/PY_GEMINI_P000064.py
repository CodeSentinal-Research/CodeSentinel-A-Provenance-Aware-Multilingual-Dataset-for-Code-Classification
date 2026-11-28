import sys, math
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        a, b = int(lines[0]), int(lines[1])
        print(math.gcd(a, b))
if __name__ == '__main__':
    main()