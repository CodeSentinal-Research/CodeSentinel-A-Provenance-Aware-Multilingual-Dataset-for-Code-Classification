from typing import List

def prime_factors(n: int) -> List[int]:
    """Checks prime status or generates prime numbers using sieve."""
    factors = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            factors.append(d)
            n //= d
        d += 1
    if n > 1:
        factors.append(n)
    return factors

if __name__ == '__main__':
    n = int(input())
    print(" ".join(map(str, prime_factors(n))))