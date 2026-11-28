import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    max_xor = 0
    mask = 0
    for i in range(31, -1, -1):
        mask |= (1 << i)
        prefixes = set()
        for x in nums:
            prefixes.add(x & mask)
        temp = max_xor | (1 << i)
        for p in prefixes:
            if temp ^ p in prefixes:
                max_xor = temp
                break
    print(max_xor)
solve()
