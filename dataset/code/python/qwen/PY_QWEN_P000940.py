import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    piles = list(map(int, d[1:n+1]))
    if all(p <= 1 for p in piles):
        print("First" if n % 2 == 0 else "Second")
    else:
        xor_sum = 0
        for p in piles: xor_sum ^= p
        print("First" if xor_sum != 0 else "Second")
solve()
