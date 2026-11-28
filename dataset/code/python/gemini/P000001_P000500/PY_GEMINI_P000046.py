import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        a, b = int(lines[0]), int(lines[1])
        print('Divisible' if a % b == 0 else 'Not Divisible')
if __name__ == '__main__':
    main()