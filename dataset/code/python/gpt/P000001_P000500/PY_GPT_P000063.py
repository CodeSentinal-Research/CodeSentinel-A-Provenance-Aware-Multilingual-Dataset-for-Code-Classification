# problem title : Print Prime Numbers in Range
# Test each number in the requested interval for primality.
l, r = map(int, input().split())
primes = []
for n in range(max(2, l), r + 1):
    is_prime = all(n % d for d in range(2, int(n ** 0.5) + 1))
    if is_prime:
        primes.append(n)
print(*primes)
