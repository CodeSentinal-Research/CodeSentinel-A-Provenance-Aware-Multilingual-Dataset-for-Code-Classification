def ext_gcd(a: int, b: int):
    """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
    if b == 0:
        return a, 1, 0
    g, x1, y1 = ext_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

if __name__ == '__main__':
    a, b = map(int, input().split())
    g, x, y = ext_gcd(a, b)
    print(f"{g} {x} {y}")