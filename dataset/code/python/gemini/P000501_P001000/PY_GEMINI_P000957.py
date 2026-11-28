import math

def verify_bezout(a: int, b: int, x: int, y: int) -> bool:
    return a * x + b * y == math.gcd(a, b)

if __name__ == '__main__':
    a, b, x, y = map(int, input().split())
    print("YES" if verify_bezout(a, b, x, y) else "NO")