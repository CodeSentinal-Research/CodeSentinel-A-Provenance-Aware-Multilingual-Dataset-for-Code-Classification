def gcd(a: int, b: int) -> int:
    """Computes the Greatest Common Divisor (GCD) using Euclidean algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a: int, b: int) -> int:
    """Computes the Least Common Multiple (LCM)."""
    if a == 0 or b == 0:
        return 0
    return (a * b) // gcd(a, b)

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm(a, b))