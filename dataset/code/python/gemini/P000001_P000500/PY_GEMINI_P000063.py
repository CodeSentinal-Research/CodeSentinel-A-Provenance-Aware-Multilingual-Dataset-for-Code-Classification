import sys
def is_prime(n):
    """Checks prime status or generates prime numbers using sieve."""
    if n <= 1: return False
    if n <= 3: return True
    if n % 2 == 0 or n % 3 == 0: return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0: return False
        i += 6
    return True
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        l, r = int(lines[0]), int(lines[1])
        primes = [str(x) for x in range(l, r + 1) if is_prime(x)]
        print(' '.join(primes))
if __name__ == '__main__':
    main()