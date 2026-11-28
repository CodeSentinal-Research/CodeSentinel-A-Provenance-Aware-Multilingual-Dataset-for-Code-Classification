import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    deck = list(map(int, input_data[1:n+1]))
    deck.sort(reverse=True)
    res = [0] * n
    idx = 0
    for i in range(n):
        if i % 2 == 0:
            res[i] = deck[idx]
            idx += 1
    q = [i for i in range(n) if i % 2 != 0]
    for i in range(idx, n):
        if q:
            q.pop(0)
            if q:
                q.append(q.pop(0))
            res[q[0] if q else 0] = deck[i]
    print(" ".join(map(str, res)))
solve()
