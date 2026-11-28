def count_coprime(n: int, r: int) -> int:
    """Checks prime status or generates prime numbers using sieve."""
    primes = []
    temp = n
    d = 2
    while d * d <= temp:
        if temp % d == 0:
            primes.append(d)
            while temp % d == 0:
                temp //= d
        d += 1
    if temp > 1:
        primes.append(temp)

    m = len(primes)
    divisible_count = 0
    for mask in range(1, 1 << m):
        prod = 1
        bits = 0
        for i in range(m):
            # If current bit is set, multiply base into result
            if (mask >> i) & 1:
                prod *= primes[i]
                bits += 1
        # If current bit is set, multiply base into result
        if bits % 2 == 1:
            divisible_count += r // prod
        else:
            divisible_count -= r // prod
    return r - divisible_count

if __name__ == '__main__':
    n, r = map(int, input().split())
    print(count_coprime(n, r))