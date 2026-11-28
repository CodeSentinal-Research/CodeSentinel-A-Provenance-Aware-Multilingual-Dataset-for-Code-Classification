import sys, math
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        n = int(s)
        total = sum(math.factorial(int(d)) for d in s if d.isdigit())
        print('Strong' if total == n else 'Not Strong')
if __name__ == '__main__':
    main()