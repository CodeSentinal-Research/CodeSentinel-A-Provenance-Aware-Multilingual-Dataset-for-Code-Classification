def gcd(a: int, b: int) -> int:
    """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
    while b:
        a, b = b, a % b
    return a

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(gcd(a, b))