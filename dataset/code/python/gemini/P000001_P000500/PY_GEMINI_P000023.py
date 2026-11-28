import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        fib = []
        a, b = 0, 1
        for _ in range(n):
            fib.append(str(a))
            a, b = b, a + b
        print(" ".join(fib))

if __name__ == '__main__':
    main()