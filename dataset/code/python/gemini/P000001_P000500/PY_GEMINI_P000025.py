import sys

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        sign = -1 if n < 0 else 1
        rev = int(str(abs(n))[::-1])
        print(sign * rev)

if __name__ == '__main__':
    main()