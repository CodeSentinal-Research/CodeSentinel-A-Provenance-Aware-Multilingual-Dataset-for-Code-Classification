import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        a, b, c = float(lines[0]), float(lines[1]), float(lines[2])
        valid = (a + b > c) and (a + c > b) and (b + c > a)
        print('Valid' if valid else 'Invalid')
if __name__ == '__main__':
    main()