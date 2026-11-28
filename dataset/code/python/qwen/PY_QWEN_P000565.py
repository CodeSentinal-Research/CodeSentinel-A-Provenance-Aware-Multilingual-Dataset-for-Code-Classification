import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    rows = int(input_data[0])
    cols = int(input_data[1])
    rC = int(input_data[2])
    cC = int(input_data[3])
    res = []
    for i in range(rows):
        for j in range(cols):
            res.append([i, j, abs(i - rC) + abs(j - cC)])
    res.sort(key=lambda x: x[2])
    print(" ".join(f"[{x[0]},{x[1]}]" for x in res))
solve()
