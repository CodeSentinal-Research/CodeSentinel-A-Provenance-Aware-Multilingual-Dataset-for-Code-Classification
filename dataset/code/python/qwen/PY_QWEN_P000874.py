import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    encoded = list(map(int, d[1:n+1]))
    total_xor = 0
    for i in range(1, n + 2):
        total_xor ^= i
    odd_encoded_xor = 0
    for i in range(1, len(encoded), 2):
        odd_encoded_xor ^= encoded[i]
    first = total_xor ^ odd_encoded_xor
    res = [first]
    for x in encoded:
        res.append(res[-1] ^ x)
    print(" ".join(map(str, res)))
solve()
