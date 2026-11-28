import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    arr.pop(n - k)
    print(" ".join(map(str, arr)))
solve()
