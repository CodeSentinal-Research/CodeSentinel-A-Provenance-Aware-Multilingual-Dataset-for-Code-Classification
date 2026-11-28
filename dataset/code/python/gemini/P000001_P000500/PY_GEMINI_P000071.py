import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        a, b, c = float(lines[0]), float(lines[1]), float(lines[2])
        if a == b == c:
            print('Equilateral')
        elif a == b or b == c or a == c:
            print('Isosceles')
        else:
            print('Scalene')
if __name__ == '__main__':
    main()