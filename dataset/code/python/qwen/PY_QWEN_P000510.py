import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    prices = list(map(int, input_data[1:n+1]))
    res = []
    for i in range(n):
        disc = 0
        for j in range(i + 1, n):
            if prices[j] <= prices[i]:
                disc = prices[j]
                break
        res.append(prices[i] - disc)
    print(" ".join(map(str, res)))
solve()
