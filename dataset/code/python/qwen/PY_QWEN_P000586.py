import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    res = []
    for i in range(0, n, k):
        res.extend(arr[i:i+k][::-1])
    print(" ".join(map(str, res)))
solve()
