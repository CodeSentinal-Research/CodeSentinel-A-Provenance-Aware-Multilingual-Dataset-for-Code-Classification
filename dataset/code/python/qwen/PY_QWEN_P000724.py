import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, words = int(d[0]), d[1:]
    masks = []
    for w in words:
        mask = 0
        valid = True
        for c in w:
            bit = 1 << (ord(c) - ord('a'))
            if mask & bit: valid = False; break
            mask |= bit
        if valid: masks.append((len(w), mask))
    res = 0
    def rec(idx, curr_mask, curr_len):
        nonlocal res
        res = max(res, curr_len)
        for i in range(idx, len(masks)):
            l, m = masks[i]
            if not (curr_mask & m):
                rec(i + 1, curr_mask | m, curr_len + l)
    rec(0, 0, 0)
    print(res)
solve()
