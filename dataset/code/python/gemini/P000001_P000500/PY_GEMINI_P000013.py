import sys
import math

def main():
    lines = sys.stdin.read().split()
    if lines:
        r = float(lines[0])
        pi = 3.14159
        area = pi * r * r
        print(f"{area:.5f}")

if __name__ == '__main__':
    main()