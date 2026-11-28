import sys
import math

def main():
    lines = sys.stdin.read().split()
    if lines:
        n = int(lines[0])
        print(math.factorial(n))

if __name__ == '__main__':
    main()