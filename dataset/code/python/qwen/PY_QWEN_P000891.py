import sys
def solve():
    n = int(sys.stdin.read().split()[0])
    def is_prime(x):
        if x < 2: return False
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0: return False
        return True
    curr = n + 1
    while not is_prime(curr):
        curr += 1
    print(curr)
solve()
