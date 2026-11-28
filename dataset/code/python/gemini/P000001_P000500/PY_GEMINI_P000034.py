import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        if n <= 1:
            print('Not Perfect')
            return
        total = sum(i for i in range(1, n) if n % i == 0)
        print('Perfect' if total == n else 'Not Perfect')
if __name__ == '__main__':
    main()