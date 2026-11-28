def count_ways_tile(n: int) -> int:
    MOD = 10**9 + 7
    if n <= 2:
        return n
    a, b = 1, 2
    for _ in range(3, n + 1):
        a, b = b, (a + b) % MOD
    return b

if __name__ == '__main__':
    n = int(input())
    print(count_ways_tile(n))