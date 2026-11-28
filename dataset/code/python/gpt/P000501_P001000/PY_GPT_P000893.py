# problem title : Distinct Prime Factors
# Solve the stated task using standard input and standard output.
from typing import List

def distinct_prime_factors(n: int) -> List[int]:
    factors = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            factors.append(d)
            while n % d == 0:
                n //= d
        d += 1
    if n > 1:
        factors.append(n)
    return factors

if __name__ == '__main__':
    n = int(input())
    print(" ".join(map(str, distinct_prime_factors(n))))
