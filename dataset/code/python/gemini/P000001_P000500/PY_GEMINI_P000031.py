import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        factors = [str(i) for i in range(1, n + 1) if n % i == 0]
        print(' '.join(factors))
if __name__ == '__main__':
    main()