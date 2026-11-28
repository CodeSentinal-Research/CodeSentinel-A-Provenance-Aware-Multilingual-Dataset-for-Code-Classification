Here is the Python code for your problem:


def power(a, b, MOD):
    a %= MOD
    if b == 0:
        return 1
    half = power(a, b // 2, MOD)
    if b % 2:
        return (half * half * a) % MOD
    else:
        return (half * half) % MOD

def inverse(a, MOD):
    return power(a, MOD - 2, MOD)

def countGoodNumbers(N):
    MOD = 10**9 + 7
    even_digits = [0, 1, 2, 4, 6, 8][:N % 10 + 1]
    prime_digits = [2, 3, 5, 7]
    even_digits_count = [1, 1, 4, 4, 4][:N % 10 + 1]
    total = 0
    for i in range(len(prime_digits)):
        if N % 2:
            total += power(prime_digits[i], N // 2 + 1, MOD) * even_digits_count[N % 10] * even_digits[N % 10]
            total %= MOD
        else:
            total += power(prime_digits[i], N // 2, MOD) * even_digits_count[N % 10] * even