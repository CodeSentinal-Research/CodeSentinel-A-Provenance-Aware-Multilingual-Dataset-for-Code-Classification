def count_derangements(n: int) -> int:
    MOD = 10**9 + 7
    if n == 1:
        return 0
    if n == 2:
        return 1
    a, b = 0, 1
    for i in range(3, n + 1):
        c = ((i - 1) * (a + b)) % MOD
        a = b
        b = c
    return b

if __name__ == '__main__':
    n = int(input())
    print(count_derangements(n))