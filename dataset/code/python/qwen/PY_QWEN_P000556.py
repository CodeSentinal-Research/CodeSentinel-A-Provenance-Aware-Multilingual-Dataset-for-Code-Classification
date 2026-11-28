import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    m = int(input_data[0])
    n = int(input_data[1])
    grid = []
    idx = 2
    for _ in range(m):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
    print("-1")
solve()
