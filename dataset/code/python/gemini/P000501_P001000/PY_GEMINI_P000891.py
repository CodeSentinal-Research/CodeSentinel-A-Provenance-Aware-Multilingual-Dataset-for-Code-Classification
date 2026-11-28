def is_prime(n: int) -> bool:
    """Checks prime status or generates prime numbers using sieve."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def next_prime(n: int) -> int:
    """Checks prime status or generates prime numbers using sieve."""
    cand = n + 1
    while not is_prime(cand):
        cand += 1
    return cand

if __name__ == '__main__':
    n = int(input())
    print(next_prime(n))