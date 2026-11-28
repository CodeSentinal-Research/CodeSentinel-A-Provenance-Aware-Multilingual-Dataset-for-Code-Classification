def count_strings(n: int) -> int:
    MOD = 10**9 + 7
    if n == 1:
        return 2
    a, b = 1, 2
    for _ in range(2, n + 1):
        a, b = b, (a + b) % MOD
    return b

if __name__ == '__main__':
    n = int(input())
    print(count_strings(n))