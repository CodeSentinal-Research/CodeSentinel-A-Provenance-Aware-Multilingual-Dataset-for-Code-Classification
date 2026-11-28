# problem title : Friends Pairing Problem
# Solve the stated task using standard input and standard output.
def count_friends_pairings(n: int) -> int:
    MOD = 10**9 + 7
    if n <= 2:
        return n
    a, b = 1, 2
    for i in range(3, n + 1):
        c = (b + (i - 1) * a) % MOD
        a = b
        b = c
    return b

if __name__ == '__main__':
    n = int(input())
    print(count_friends_pairings(n))
