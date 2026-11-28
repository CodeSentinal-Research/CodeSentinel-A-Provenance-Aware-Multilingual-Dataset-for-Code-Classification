# problem title : Find Sum of Prime Numbers up to N
# Sieve all primes up to N, then sum the marked values.
n = int(input())
prime = [True] * (n + 1)
if n >= 0: prime[0] = False
if n >= 1: prime[1] = False
for p in range(2, int(n ** 0.5) + 1):
    if prime[p]:
        prime[p * p:n + 1:p] = [False] * (((n - p * p) // p) + 1)
print(sum(i for i, ok in enumerate(prime) if ok))
