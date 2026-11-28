import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    res = []
    for x in arr:
        if not res or res[-1] != x:
            res.append(x)
    print(" ".join(map(str, res)))
solve()
