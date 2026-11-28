import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    for i in range(0, n - 1, 2):
        arr[i], arr[i+1] = arr[i+1], arr[i]
    print(" ".join(map(str, arr)))
solve()
